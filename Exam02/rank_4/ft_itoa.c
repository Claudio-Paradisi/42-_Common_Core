/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:53:54 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/21 15:56:57 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     num_len(int nbr)
{
     int    count;

     count = 0;
     if (nbr <= 0)
     {
        count++;
        if (nbr < 0)
            nbr = nbr * - 1;
     }
     while(nbr != 0)
     {
        count++;
        nbr = nbr / 10;
     }
     return (count);
}

char    *init_str(int len)
{
    char    *buffer;

    buffer = (char *)malloc(len +  1);
    if (!buffer)
        return(NULL);
    buffer[0] = '0';
    return (buffer);
}

char    *ft_itoa(int nbr)
{
    char        *itoed;
    int         len;
    int         i;
    long int    n;

    
    n = nbr;
    len = num_len(nbr);
    i = len - 1;
    itoed = init_str(len);
    if(!itoed)
        return (NULL);
    if (n < 0)
        n = n * -1;
    while(n != 0)
    {
        itoed[i] = (n % 10) + '0';
        n = n / 10;
        i--;
    }
    if (nbr < 0)
        itoed[0] = '-';
    itoed[len] = '\0';
    return(itoed);
}

int     main()
{
    char *str;
    int num;

    num = -582685;
    str = ft_itoa(num);
    printf("%s\n", str);
    free(str);
    return 0;
}