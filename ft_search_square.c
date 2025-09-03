/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:52:11 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 16:58:31 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
void ft_search_square(char **mat, int n_lines, int nCols, int dimension, char empty_char, char printing_char, int* aux_i, int* aux_j, int* aux_dimension)
{
	int i;
	int j;
	//int aux_i;
	//int aux_j;
	//int aux_dimension;

	//printf("dimension=%d",dimension);
	i = 0;
	//i = 5;
	//
	while (i + dimension <= n_lines)
	{
		j = 0;
		//j = 25;
		//
		//printf("------------");
		//printf("\ndimension= %d \n", dimension);
		while (j + dimension <= nCols)
		{
			//printf("\ni =%d j= %d\n", i, j);
			if (ft_check_square(mat, i, j, dimension, empty_char) == 1)
			{
				if(dimension > *aux_dimension)
				{
					ft_max(aux_dimension, dimension);
					*aux_i = i;
					*aux_j = j; 

				}
				else 
				{
					ft_min(aux_i, i);
					ft_min(aux_j, j);
					ft_max(aux_dimension, dimension);
				}
				
				//printf("\n i = %d, j = %d, dimension =%d\n", i, j, dimension);
				//printf("\n aux_i = %d, aux_j = %d, aux_dimension =%d\n", aux_i, aux_j, aux_dimension);
				ft_search_square(mat, n_lines, nCols, dimension + 1, empty_char, printing_char, aux_i, aux_j,aux_dimension);
				return;
			}
			j++;
		}
		i++;
	}
	//printf("aux_i = %d,aux_j = %d, aux_dimension = %d, printing_char = %c ", *aux_i, *aux_j, *aux_dimension, printing_char );
	ft_create_square(mat, *aux_i, *aux_j, *aux_dimension, printing_char);
	return;
}
