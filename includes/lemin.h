/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:29:27 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/04 15:01:21 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>

typedef struct	s_lm
{
	int			ant_nb;
	t_list		*ants;
	int			room_nb;
	t_list		*rooms;
	int			tube_nb;
	t_list		*tubes;
}				t_lm;

# include <lemin.h>
# include <ft_create_rooms.h>
# include <ft_lemin_parser.h>
# include <ft_init_lm.h>

#endif /* !LEMIN_H */
