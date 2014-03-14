#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:46 by vlehuger          #+#    #+#              #
#    Updated: 2014/03/14 11:39:36 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC =		cc

FLAGS =		-Wall -Wextra -Werror

NAME =		lemin

SRCS =		\
			srcs/main.c \
			srcs/error.c \
			srcs/display.c \
			srcs/weighting.c \
			srcs/parser/parser.c \
			srcs/parser/get_ant.c \
			srcs/parser/get_room.c \
			srcs/parser/is_room.c \
			srcs/parser/is_command.c\
			srcs/parser/init_room.c\
			srcs/parser/fill_room.c\
			srcs/parser/get_link.c\
			srcs/parser/is_link.c\
			srcs/parser/fill_link.c\


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
