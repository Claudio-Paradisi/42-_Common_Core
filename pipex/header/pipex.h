/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:19:50 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/06 17:35:22 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdint.h>

typedef struct s_pipex
{
	pid_t		pid;
	int			**pipes;
	int			infile;
	int			outfile;
	int			cmd_count;
	char		*path;
	char		**cmd_paths;
	char		***cmd_args;
	char		*cmd;
}				t_pipex;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void    free_matrix(char **matrix);
void    *ft_calloc(size_t nmemb, size_t size);
void	execute_child(t_pipex *pipex, int i, char **envp);
void    msg_error(int num);
void    init_pipes(t_pipex *pipex);
void    free_pipes(t_pipex *pipex);

#endif