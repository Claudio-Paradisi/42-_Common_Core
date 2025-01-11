/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:02:04 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/11 15:59:40 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

	#ifndef BUFFER_SIZE 
	#define BUFFER_SIZE 1
#endif

#define TRUE        1
#define FALSE       0

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strndup(char *str, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
void	upgrade_stash(char *stash);
int     check_stash(char *stash, size_t *bsn_pos);
#endif
