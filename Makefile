# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fliraud- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 11:09:13 by fliraud-          #+#    #+#              #
#    Updated: 2025/09/03 11:21:03 by fliraud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== BASIC SETUP =====

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq

# ===== FILE LISTS =====

SRCS = main.c ft_check_square.c ft_create_square.c ft_file_to_mat.c ft_print_matrix.c ft_search_square.c

OBJS = $(SRCS:.c=.o)

# ===== BUILD RULES =====
# Default command: just type 'make' to build everything
all: $(NAME)

# How to create the final program: link all .o files together
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule for building any .o file from its .c file
# % is a wildcard: for any file, if you need file.o, build it from file.c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ===== CLEANUP RULES =====
# Remove all compiled .o files (type 'make clean')
clean:
	rm -f $(OBJS)

# Remove both .o files AND the final program (type 'make fclean')
fclean: clean
	rm -f $(NAME)

# Completely rebuild from scratch (clean + build)
re: fclean all

# ===== COMMANDS =====
# - Make		builds the program creating .o files (all)
# - Make clean		cleans the program removing .o files
# - Make fclean		cleans the program removing .o & bsq
# - Make re		builds + cleans
