/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:52:11 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 00:52:18 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int ft_check_square(char **mat, int i, int j, int dimension, char empty_char);
void ft_create_square(char **mat, int i, int j, int dimension, char printing_char);

void ft_min(int *aux, int i)
{
	if (*aux > i)
		*aux = i;
}

void ft_max(int *aux, int i)
{
	if (*aux < i)
		*aux = i;
}
//ft_search_square(char **mat, int n_lines, int length_line, int dimension, char empty_char, char printing_char)
void ft_search_square(char **mat, int n_lines, int nCols, int dimension, char empty_char, char printing_char)
{
	int i;
	int j;
	int aux_i;
	int aux_j;
	int aux_dimension;

	printf("dimension=%d",dimension);

	aux_i = 99;
	aux_j = 99;
	i = 0;
	aux_dimension = 0;
	while (i < n_lines)
	{
		j = 0;
		while (j < nCols)
		{
			printf("\ni =%d j= %d", i, j);

			if (ft_check_square(mat, i, j, dimension, empty_char) == 1)
			{
				ft_min(&aux_i, i);
				ft_min(&aux_j, j);
				ft_max(&aux_dimension, dimension);
				//printf("\n i = %d, j = %d, dimension =%d\n", i, j, dimension);
				//printf("\n aux_i = %d, aux_j = %d, aux_dimension =%d\n", aux_i, aux_j, aux_dimension);
				ft_search_square(mat, n_lines, nCols, dimension + 1, empty_char, printing_char);
				return;
			}
			j++;
		}
		i++;
	}
	ft_create_square(mat, aux_i, aux_j, aux_dimension, printing_char);
}
