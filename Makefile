#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:46 by vlehuger          #+#    #+#              #
#    Updated: 2014/02/18 15:00:35 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC =		cc

FLAGS =		-Wall -Wextra -Werror

NAME =		lemin

SRCS =		\
			srcs/lemin.c \
			srcs/ft_add_connect.c \
			srcs/ft_create_rooms.c \
			srcs/ft_error.c \
			srcs/ft_get_first_word.c \
			srcs/ft_get_rooms_struct.c \
			srcs/ft_get_tubes.c \
			srcs/ft_init_lm.c \
			srcs/ft_lemin_parser.c \
			srcs/ft_move.c \
			srcs/ft_solve.c \
			srcs/ft_weighting.c \
			srcs/ft_test_way.c \

OBJS =		$(SRCS:.c=.o)

LIBFT =		-L ./libft -lft

HEADLIB =	-I ./libft/includes

LEMINLIB = -I ./includes

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			$(CC) -o $(NAME) $(OBJS) $(LIBFT)

%.o:		%.c
			$(CC) $(FLAGS) -o $@ -c $< $(HEADLIB) $(LEMINLIB)

clean:
			make clean -C libft/
			rm -f $(OBJS)

fclean:		clean
			make fclean -C libft/
			rm -f $(NAME)

re :		fclean all

.PHONY:		clean
