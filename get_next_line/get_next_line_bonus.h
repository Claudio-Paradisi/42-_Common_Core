/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:07:20 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/14 15:07:55 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# define TRUE 1
# define FALSE 0

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strndup(char *str, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
void	upgrade_stash(char *stash);
int		check_stash(char *stash, size_t *bsn_pos);
char	*gnl_free_line(char *line);
#endif
