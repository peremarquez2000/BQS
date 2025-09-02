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