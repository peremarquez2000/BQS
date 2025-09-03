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

#include <unistd.h>
#include <stdio.h>
int ft_check_square(char **mat, int i, int j, int dimension, char empty_char)
{
    int checker;
    int z;

    checker = 0;
    while (i < dimension)
    {
        z = j;
        while (z < dimension)
        {
            if (mat[i][z] == empty_char)
                checker++;
            else
                return (0);
            //printf("\nz=%d\n", z);
            z++;
        }
        //printf("\nchecker=%d\n", checker);
        i++;
    }
    if (checker == dimension * dimension)
        return (1);
    return (0);
}
