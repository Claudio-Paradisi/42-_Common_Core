/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparadis <cparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:04:58 by cparadis          #+#    #+#             */
/*   Updated: 2025/01/24 23:16:59 by cparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void 	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
    unsigned int j;
    int temp;

    if (size < 2)
        return;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1 - i)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    int tab[] = {42, 7, 7, 73, 23};
    unsigned int size = 5;

    sort_int_tab(tab, size);

    for (unsigned int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    return 0;
}