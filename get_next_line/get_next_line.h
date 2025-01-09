/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:02:04 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/09 16:42:08 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

	#ifndef BUFFER_SIZE 
	#define BUFFER_SIZE 3
#endif

#define TRUE        1
#define FALSE       0

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strndup(const char *str);
//char    *ft_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strljoin(char *s1, char *s2);
//char	**gnl_split(const char *s, char c);
#endif
