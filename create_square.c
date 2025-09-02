#include <unistd.h>

void ft_create_square(char **mat, int dimension, char printing_char)
{
	int checker;
	int i;
	int j;

	checker = 0;
	i = 0;
	while (i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			mat[i][j] = printing_char;
			j++;
		}
		i++;
	}
}