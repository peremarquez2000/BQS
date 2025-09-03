/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:51:08 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 09:30:46 by pemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void ft_print_matrix(char **mat, int n_lines, int n_cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_lines)
	{
		j = 0;
		while (j < n_cols)
		{
			write(1,&mat[i][j], 1);
			j++;
		}
		write(1,"\n",1);
		i++;
		
	}
}
