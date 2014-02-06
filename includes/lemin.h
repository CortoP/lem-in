/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:29:27 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 17:40:33 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define START 1
# define END 2

# include <libft.h>

typedef struct		s_lm
{
	int				ant_nb;
	t_list			*ants;
	int				room_nb;
	t_list			*rooms;
	int				tube_nb;
	t_list			*tubes;
}					t_lm;

typedef struct		s_room
{
	int				id;
	int				flag;
	char			*name;
	struct s_room	*next;
}					t_room;


# include <lemin.h>
# include <ft_create_rooms.h>
# include <ft_lemin_parser.h>
# include <ft_init_lm.h>

#endif /* !LEMIN_H */
