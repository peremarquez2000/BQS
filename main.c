/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:53:52 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 09:44:00 by pemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**file_to_mat(char *file_str,char *obs, char *emp, char *full, int *dim, int *nCol);
void	ft_print_matrix(char **mat, int length_line, int n_lines);
void	ft_search_square(char **mat, int n_lines, int length_line, int dimension, char empty_char, char printing_char);
int		ft_check_square(char **mat, int i, int j, int dimension, char empty_char);

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

int	main(int argc, char **argv)
{
	char	**matrix;
	char	obs;
	char	emp;
	char	full;
	int		dim;
	int		i;
	int	nCol;

	// Verificar argumentos
	if (argc != 2)
	{
		write(2, "Usage: ./program map_file\n", 26);
		return (1);
	}

	// Llamar a la función
	matrix = file_to_mat(argv[1], &obs, &emp, &full, &dim, &nCol);
	if (!matrix)
	{
		write(2, "Error: Could not read file or invalid format\n", 44);
		return (1);
	}

	// Mostrar información del mapa
	write(1, "Map info:\n", 10);
	write(1, "Dimension: ", 11);
	char dim_str[12];
	int n = dim;
	int len = 0;
	if (n == 0) {
		dim_str[len++] = '0';
	} else {
		int temp = n;
		while (temp) {
			len++;
			temp /= 10;
		}
		temp = len;
		while (n) {
			dim_str[--temp] = '0' + (n % 10);
			n /= 10;
		}
	}
	dim_str[len] = '\0';
	write(1, dim_str, len);
	write(1, "\nEmpty: '", 9);
	write(1, &emp, 1);
	write(1, "'\nObstacle: '", 13);
	write(1, &obs, 1);
	write(1, "'\nFull: '", 9);
	write(1, &full, 1);
	write(1, "'\n\nMatrix:\n", 11);

	// Mostrar la matriz
	i = 0;
	while (i < dim)
	{
		write(1, matrix[i], nCol);
		write(1, "\n", 1);
		i++;
	}

	//Operaciones del juego
	printf("\n----------------------\nOPERACIONES DEL JUEGO\n-----------------------\n");

	ft_print_matrix(matrix, dim, nCol);
	//printf("%d", ft_check_square(matrix, 0, 0, 4, '.'));
	//printf("es bien?:%d", matrix[1][4] == '.');
	ft_search_square(matrix, dim, nCol, 5, emp, full);
	ft_print_matrix(matrix, dim, nCol);
	//ft_search_square(char **mat, int n_lines, int length_line, int dimension, char empty_char, char printing_char)
	//check_square(char **mat, int i, int j, int dimension, char empty_char);
	/////////////////////////////////////////////////////////////////////////////////////
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


