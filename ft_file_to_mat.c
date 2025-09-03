/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:53:52 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 03:56:36 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**file_to_mat(char *file_str,char *obs, char *emp, char *full, int *dim)
{
	char	**matrix;
	int	file;
    char buffer[4096];
	int bytes_read;
	int	i;
	int	j;
	int	k;
	int	dim2;

	dim2 = 0;
	i = 0;
	j = 0;
	k = 0;
	file = open(file_str, O_RDONLY);
	if (file == -1)
		return (NULL);

	bytes_read = read(file, buffer, 4096);
	if (bytes_read <= 0)
	{
		close (file);
		return (NULL);
	}
	while (buffer[i] >= '0' && buffer[i] <= '9')
	{
		dim2 = dim2 * 10 + (buffer[i] - '0');
		i++;
	}
	*dim = dim2;
	*emp = buffer[i++];
	*obs = buffer[i++];
	*full = buffer[i++];
	if (buffer[i] == '\n')
		i++; 
	matrix = (char **)malloc(*dim * sizeof(char *));
	if (!matrix)
	{
		close(file);
		return (NULL);
	}
	j = 0;
	while (j <*dim)
	{
		matrix[j] = (char *)malloc(*dim * sizeof(char));
		if (!matrix[j])
		{
			while (--j >= 0)
				free(matrix[j]);
			free(matrix);
			close(file);
			return (NULL);
		}
		j++;
	}
	k = i;
	j = 0;
	while (j < *dim && k < bytes_read)
	{
		i = 0;
		while (i < *dim && k < bytes_read)
		{
			if (buffer[k] == '\n')
			{
				k++;
				continue;
			}
			matrix[j][i] = buffer[k];
			i++;
			k++;
		}
		j++;
	}
	close(file);
	return (matrix);
}

//HASTA AQUI!!! AQUI CODIGO MAIN PRUEBA
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

	// Verificar argumentos
	if (argc != 2)
	{
		write(2, "Usage: ./program map_file\n", 26);
		return (1);
	}

	// Llamar a la función
	matrix = file_to_mat(argv[1], &obs, &emp, &full, &dim);
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
		write(1, matrix[i], dim);
		write(1, "\n", 1);
		i++;
	}

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


