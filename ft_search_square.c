#include <unistd.h>
int check_square(char **mat, int i, int j, int dimension, char empty_char);
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

void ft_search_square(char **mat, int dimension, char empty_char, char printing_char)
{
	int i;
	int j;
	int aux_i;
	int aux_j;
	int aux_dimension;

	aux_i = 99;
	aux_j = 99;
	while (i < n_lines)
	{
		j = 0;
		while (j < length_line)
		{
			if (check_square(mat, i, j, dimension, empty_char) == 1)
			{
				ft_min(&aux_i, i);
				ft_min(&aux_j, j);
				ft_max(&aux_dimension, dimension);
				ft_search_square(mat, dimension + 1, empty_char, printing_char);
				return;
			}
			j++;
		}
		i++;
	}
	ft_create_square(mat, aux_i, aux_j, aux_dimension, printing_char);
}