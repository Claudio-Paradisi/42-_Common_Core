/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 12:10:04 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"
/*
/ a program that emulates the work of the pipes of the shell using an infile
/ as an input and saves the output in an outfile 
/ < infile cmd | cmd > outfile
*/

/*
/ this function returns the string of the matrix envp (variable environment)
/ when it founds the substring "PATH="
*/
static char 	*find_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return(*envp + 5);
		envp++;
	}
	return (NULL);
}
/*
/ this function opens our infile and outfile
*/
static void		open_files(t_pipex *pipex, char **av, int ac)
{
    pipex->infile = open(av[1], O_RDONLY);
	/*
	/ if open returns -1 we have to send an error message but the program
	/ must continue working skipping the first command, to do so
	/ we set the first argument as null to avoid leaks and we brut force
	/ the first command to avoid errors (echo -n writes nothing)
	*/
    if (pipex->infile < 0)
	{
		ft_putstr_fd("Error opening the infile! ¯\\_(ツ)_/¯\n", 2);
		av[1] = NULL;
		av[2] = "echo -n";
	}
	/*
	/ if outfile doesn't exist we have to create it, if it does exist we
	/ have to delete its content before saving the output
	*/
	pipex->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
    if (pipex->outfile < 0)
		msg_error(1);
}

/*
/ int this function we create every child process we need and we tell the 
/ father process to wait the execution of every child
*/
static void		processing(t_pipex *pipex, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	/*
	/ we create the pipes
	*/
	init_pipes(pipex);
	/*
	/ for each command we found we create a child process
	/ and we execute the eventual command
	*/
	while (i < pipex->cmd_count)
	{
		pipex->pid = fork();
		if (pipex->pid < 0)
			msg_error(5);
		if (pipex->pid == 0)
			execute_child(pipex, i, envp);
		i++;
	}
	/*
	/ we free every pipes to manage memory leak
	*/
	free_pipes(pipex);
	/*
	/ for each child created we tell the father to wait
	*/
	while (j < pipex->cmd_count)
	{
		wait(NULL);
		j++;
	}
}

/*
/ in this function we initialize our struct
*/
static t_pipex		init_t_pipex(int ac, char **av, char **envp, int i)
{
	t_pipex pipex;
	
	pipex.cmd_count = ac - 3;
	pipex.here_doc = 0;
	open_files(&pipex, av, ac);
	pipex.path = find_path(envp);
	if (pipex.path)
    	pipex.cmd_paths = ft_split(pipex.path, ':');
	else
    	pipex.cmd_paths = NULL;
	pipex.cmd_args = ft_calloc(pipex.cmd_count + 1, sizeof(char **));
	if (!pipex.cmd_paths || !pipex.cmd_args)
        cleanup_pipex(&pipex, 3);
	while (++i < pipex.cmd_count)
        	pipex.cmd_args[i] = ft_split(av[i + 2], ' ');
	return (pipex);
}

int		main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int		i;
	
	i = -1;
	if (ac < 5)
		msg_error(2);
	if (ft_strncmp("here_doc", av[1], ft_strlen(av[1])) != 0)
	{
		pipex = init_t_pipex(ac, av, envp, i);
		processing(&pipex, envp);
		if (pipex.infile > 0)
        	close(pipex.infile);
    	if (pipex.outfile > 0)
        	close(pipex.outfile);
    	free_matrix(pipex.cmd_paths);
    	free_array_of_matrix(pipex.cmd_args);
	}
	else
	{
		if (ac < 6)
			msg_error(2);
		here_doc(&pipex, ac, av, envp);
		if (pipex.here_doc)
			unlink("here_doc_temp");
	}
	return (0);
}