#include <unistd.h>

int check_square(char **mat, int i, int j, int dimension, char empty_char)
{
    int checker;
    int z;

    checker = 0;
    while (i < dimension)
    {
        z = j;
        while (z < dimension)
        {
            if (mat[i][j] == empty_char)
                checker++;
            else
                return (0);
            z++;
        }
        i++;
    }
    if (checker == dimension * dimension)
        return (1);
    return (0);
}