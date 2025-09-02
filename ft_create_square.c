/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:51:08 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 00:51:12 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_create_square(char **mat, int i, int j, int dimension, char printing_char)
{
	int z;

	while (i < dimension)
	{
		z = j;
		while (z < dimension)
		{
			mat[i][j] = printing_char;
			z++;
		}
		i++;
	}
}
