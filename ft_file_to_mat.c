/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:53:52 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 17:22:14 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**file_to_mat(char *file_str,char *obs, char *emp, char *full, int *dim, int *nCol)
{
	char	**matrix;
	int	file;
    char buffer[4096];
	int bytes_read;
	int	i;
	int	j;
	int	k;
	int	dim2;
	int	nCol2;
	
	nCol2 = 0;
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
	//Abrimos fichero si no existe NULL, leemos
	if (!(buffer[i] >= '1' && buffer[i] <= '9'))
		return (NULL);
	while (buffer[i] >= '0' && buffer[i] <= '9')
	{
		dim2 = dim2 * 10 + (buffer[i] - '0');
		i++;
	}
	*dim = dim2;
	*emp = buffer[i++];
	*obs = buffer[i++];
	*full = buffer[i++];
	if (*emp < 32 || *emp > 126 || *obs < 32 || *obs > 126 || *full < 32 || *full > 126)
		return (NULL);
	if (buffer[i] == '\n')
		i++;
	else
		return (NULL);
	// Conseguimos Dim, Empty, Obstacle, Full chars 
	k = i;
	while (k < bytes_read && buffer[k] != '\n')
	{
		nCol2++;
		k++;
	}
	if (nCol2 < 1)
		return (NULL);
	*nCol = nCol2;
	matrix = (char **)malloc(*dim * sizeof(char *));
	if (!matrix)
	{
		close(file);
		return (NULL);
	}
	j = 0;
	while (j < *dim)
	{
		matrix[j] = (char *)malloc(nCol2 * sizeof(char));
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
		while (k < bytes_read && buffer[k] == '\n')
		        k++;
	    	while (i < nCol2 && k < bytes_read && buffer[k] != '\n')
	    	{
	        	matrix[j][i] = buffer[k];
	        	i++;
	        	k++;
	    	}
	    	while (k < bytes_read && buffer[k] != '\n')
       		 	k++;    
	    	if (k < bytes_read && buffer[k] == '\n')
	        	k++;
    
	    	j++;
	}
	close(file);
	return (matrix);
}
