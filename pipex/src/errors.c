/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:18:13 by cparadis          #+#    #+#             */
/*   Updated: 2025/03/03 11:26:43 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
/*
/ this is the function that handle errors
/ if the program calls it it will also end th process
*/
void    msg_error(int num)
{
    if (num == 0)
        perror("Error opening infile ¯\\_(ツ)_/¯\n");
    else if (num == 1)
        perror("Error opening outfile ¯\\_(ツ)_/¯\n");
    else if (num == 2)
        perror("Too few arguments ¯\\_(ツ)_/¯\n");
    else if (num == 3)
        perror("Command not found¯\\_(ツ)_/¯\n");
    else if (num == 4)
        perror("Error in creating the pipe ¯\\_(ツ)_/¯\n");
    else if (num == 5)
        perror("Error creating the child ¯\\_(ツ)_/¯\n");
    else if (num == 6)
        perror("Error executing¯\\_(ツ)_/¯\n");
    exit(127);
}

/*
/ this is the function that frees our struct
*/
void    cleanup_pipex(t_pipex *pipex, int check)
{
    if (pipex->cmd_paths)
        free_matrix(pipex->cmd_paths);
    if (pipex->cmd_args)
        free_array_of_matrix(pipex->cmd_args);
    if (pipex->infile > 0)
        close(pipex->infile);
    if (pipex->outfile > 0)
        close(pipex->outfile);
    if (pipex->pipes)
        free_pipes(pipex);
    if (pipex->here_doc)
        unlink("here_doc_tmp");
    msg_error(check);
}