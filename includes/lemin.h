/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:29:27 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/23 12:27:42 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define START 1
# define END 2

# include <libft.h>
# include <stdio.h>

typedef struct		s_tube
{
	int				room1;
	int				room2;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	int				id;
	t_list			**ant;
	int				*dist;
	int				flag;
	char			*name;
	struct s_room	**connex;
	struct s_room	*next;
	int				*end_ants;
}					t_room;

typedef struct		s_lm
{
	int				ant_nb;
	t_list			*ants;
	int				room_nb;
	t_list			*rooms;
	int				tube_nb;
	t_list			*tubes;
	t_list			**file;
}					t_lm;

# include <ft_add_connect.h>
# include <ft_create_rooms.h>
# include <ft_get_first_word.h>
# include <ft_get_rooms_struct.h>
# include <ft_get_tubes.h>
# include <ft_lemin_parser.h>
# include <ft_init_lm.h>
# include <ft_solve.h>
# include <ft_weighting.h>

void			ft_ant_swap(t_room *room, t_room *connex);
t_room			*ft_move(t_room *room);
t_room			*ft_move_start(t_room *room);
void			ft_error(void);
int			ft_test_way(t_room *start);

#endif /* !LEMIN_H */
