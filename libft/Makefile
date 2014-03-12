#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 17:01:45 by vlehuger          #+#    #+#              #
#    Updated: 2014/02/25 11:46:49 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
LD = ar
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = rcs

NAME = libft.a

SRCS = \
		ft_atod.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoa_ccount.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_put_pixel_to_image.c \
		ft_putarray.c \
		ft_putarray_fd.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcmp.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_str_to_coord.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_vector.c \
		get_coord.c \
		get_grid.c \
		get_next_line.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -I includes/ -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
