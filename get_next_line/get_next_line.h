/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:02:04 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/06 15:51:31 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 3
#define TRUE        1
#define FALSE       0

char	*get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *str, int c);
char    *ft_strdup(const char *str);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strljoin(char *s1, char *s2, size_t start, size_t bs_n_len);

#endif
