/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:14:58 by fliraud-          #+#    #+#             */
/*   Updated: 2025/09/03 12:23:37 by fliraud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

/* ====== MATRIX MANAGEMENT ====== */
char	**file_to_mat(char *file_str,char *obs, char *emp, char *full, int *dim, int *nCol);
void	ft_print_matrix(char **mat, int n_lines, int n_cols);

/* ====== SQUARE MANAGEMENT ====== */
void	ft_search_square(char **mat, int n_lines, int nCols, int dimension, char empty_char, char printing_char, int* aux_i, int* aux_j, int* aux_dimension);
int		ft_check_square(char **mat, int i, int j, int dimension, char empty_char);
void	ft_create_square(char **mat, int i, int j, int dimension, char printing_char);

/* ====== AUXILIAR FUNCTIONS ====== */
void	putstr(char *str);
void	ft_min(int *aux, int i);
void	ft_max(int *aux, int i);
#endif