/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:53:52 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 16:16:51 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// Función para procesar un solo mapa
int	process_map(char *filename)
{
	char	**matrix;
	char	obs;
	char	emp;
	char	full;
	int		dim;
	int		i;
	int		nCol;
	int		aux_i;
	int		aux_j;
	int		aux_dimension;

	matrix = file_to_mat(filename, &obs, &emp, &full, &dim, &nCol);
	if (!matrix)
	{
		write(2, "map error\n", 10);
		return (1);
	}

	// Inicializar variables para la búsqueda
	aux_i = 99;
	aux_j = 99;
	aux_dimension = 0;

	// Buscar el cuadrado más grande
	ft_search_square(matrix, dim, nCol, 1, emp, full, &aux_i, &aux_j, &aux_dimension);
	
	// Crear y mostrar el cuadrado solución
	ft_create_square(matrix, aux_i, aux_j, aux_dimension, full);
	ft_print_matrix(matrix, dim, nCol);

	// Liberar memoria
	i = 0;
	while (i < dim)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);

	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	result;

	// Si no hay argumentos, leer de entrada estándar (stdin)
	if (argc == 1)
	{
		// Aquí puedes implementar la lectura desde stdin si es necesario
		write(2, "Reading from stdin not implemented yet\n", 39);
		return (1);
	}

	// Procesar cada archivo pasado como argumento
	i = 1;
	while (i < argc)
	{
		result = process_map(argv[i]);
		
		// Imprimir salto de línea entre mapas (excepto después del último)
		if (i < argc - 1)
			write(1, "\n", 1);
		
		i++;
	}

	return (0);
}
