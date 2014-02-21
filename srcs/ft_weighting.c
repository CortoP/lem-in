/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weighting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:02:37 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/21 14:04:05 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_weighting.h>

void			ft_room_weighting(t_room *room, int dist)
{
	t_room		*tmp;

	tmp = *room->connex;
	while (*room->connex)
	{
		if (*(*room->connex)->dist > dist || *(*room->connex)->dist == -1)
		{
			*(*room->connex)->dist = dist + 1;
			ft_room_weighting(*room->connex, dist + 1);;
		}
		*room->connex = (*room->connex)->next;
	}
	*room->connex = tmp;
}

t_room			*ft_weighting(t_room *rooms)
{
	t_room		*tmp;

	tmp = rooms;
	while (rooms)
	{
		if (rooms->flag == END)
			break ;
		rooms = rooms->next;
	}
	*rooms->dist = 0;
	ft_room_weighting(rooms, 0);
	return (tmp);
}
