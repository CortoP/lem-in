#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:46 by vlehuger          #+#    #+#              #
#    Updated: 2014/03/12 15:33:16 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC =		cc

FLAGS =		-Wall -Wextra -Werror

NAME =		lemin

SRCS =		\
			srcs/main.c \
			srcs/error.c \
			srcs/parser/parser.c \
			srcs/parser/get_ant.c \
			srcs/parser/get_room.c \
			srcs/parser/is_room.c \
			srcs/parser/is_command.c\
			srcs/parser/init_room.c

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
