/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:50:52 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 00:51:00 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_check_square(char **mat, int i, int j, int dimension, char empty_char)
{
    int checker;
    int z;
    int l;
    checker = 0;
    l = i;
    while (l < dimension + i)
    {
        z = j;
        while (z < dimension + j)
        {
            //printf("z%d", z);
            if (mat[l][z] == empty_char)
                checker++;
            else
                return (0);
            z++;
        }
        //printf("\nchecker=%d\n", checker);
        l++;
    }
    if (checker == dimension * dimension)
        return (1);
    return (0);
}
