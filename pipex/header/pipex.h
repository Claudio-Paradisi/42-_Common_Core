/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:19:50 by cparadis          #+#    #+#             */
/*   Updated: 2025/02/13 18:21:23 by cparadis         ###   ########.fr       */
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
#include "../get_next_line/get_next_line.h"

typedef struct s_pipex
{
	pid_t		pid;
	int			**pipes;
	int			infile;
	int			outfile;
	int			cmd_count;
	int			here_doc;
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
void    free_array_of_matrix(char ***a_matrix);
void	ft_putstr_fd(char *str, int fd);
void    *ft_calloc(size_t nmemb, size_t size);
void	execute_child(t_pipex *pipex, int i, char **envp);
void    msg_error(int num);
void    cleanup_pipex(t_pipex *pipex, int check);
void    init_pipes(t_pipex *pipex);
void    free_pipes(t_pipex *pipex);
int		create_hd_infile(char *limiter);
void	here_doc(t_pipex *pipex, int ac, char **av, char **envp);

#endif