/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 12:44:24 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/23 12:55:57 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room			*ft_move_start(t_room *room)
{
	t_room		*tmp;

	tmp = *room->connex;
	while (*room->connex)
    {
		if (*room->ant && room->flag != END
			&& (*room->dist > *(*room->connex)->dist))
		{
			*room->connex = ft_move(*room->connex);
			ft_ant_swap(room, *room->connex);
		}
		*room->connex = (*room->connex)->next;
    }
	*room->connex = tmp;
	return (room);
}

t_room			*ft_move(t_room *room)
{
	t_room		*tmp;

	tmp = *room->connex;
	while (*room->connex)
    {
		if (*room->ant && room->flag != END
			&& (*room->dist > *(*room->connex)->dist))
		{
			*room->connex = ft_move(*room->connex);
			ft_ant_swap(room, *room->connex);
			ft_putchar('\n');
		}
      *room->connex = (*room->connex)->next;
    }
	*room->connex = tmp;
	return (room);
}
