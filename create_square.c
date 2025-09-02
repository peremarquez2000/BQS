#include <unistd.h>

void ft_create_square(char **mat, int dimension, char printable_char, char empty_char, char obstacle_char)
{
	int checker;
	int i;

	checker = 0;
	i = 0;
	while (i < dimension)
	{
		j = 0;
		while (j < dimension)
		{
			mat[i][j] = printable_char;
		}
		i++;
	}
}