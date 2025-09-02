#include <unistd.h>

int check_square(char **mat, int i, int j, int dimension, char empty_char)
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
            if (mat[i][j] == empty_char)
                checker++;
            else
                return (0);
        }
        i++;
    }
    if (checker == dimension * dimension)
        return (1);
    return (0);
}