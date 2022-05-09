# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 01:27:09 by ltulune           #+#    #+#              #
#    Updated: 2020/12/30 06:46:09 by ltulune          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = ft_printf.c ft_get_spec_functions.c ft_print_width.c ft_print_c.c \
	ft_print_s.c ft_check_fpar_for_negative.c ft_print_percent.c \
	ft_print_p.c ft_int_to_hex.c ft_print_di.c \
	ft_itoa_mod.c ft_print_u.c ft_length_sp.c \
	ft_print_x.c ft_print_pidux.c \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) $< -o $@ -I.

$(NAME): $(OBJS) ft_printf.h
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
