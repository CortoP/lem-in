/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_connect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:15:29 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/21 15:26:49 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_add_connect.h>

t_room			*ft_copy_room(t_room *room)
{
	t_room		*copy;

	copy = (t_room *)malloc(sizeof(t_room));
	if (copy)
	{
		copy->id = room->id;
		copy->dist = room->dist;
		copy->flag = room->flag;
		copy->ant = room->ant;
		copy->name = ft_strdup(room->name);
		copy->connex = room->connex;
		if (room->flag == END)
			copy->end_ants = room->end_ants;
		copy->next = NULL;
		return (copy);
	}
	return (NULL);
}

t_room			*ft_connect_room(t_room *room, t_room *list, int id)
{
	t_room		*tmp;

	while (list)
	{
		if (id == list->id)
		{
			if (!room)
				return (ft_copy_room(list));
			else
			{
				tmp = room;
				while (room->next)
					room = room->next;
				room->next = ft_copy_room(list);
				return (tmp);
			}
		}
		list = list->next;
	}
	return (NULL);
}

t_room			*ft_test_tube(int test_id, int connect_id, t_room *rooms)
{
	t_room		*tmp;

	tmp = rooms;
	while (rooms)
	{
		if (rooms->id == test_id)
			*rooms->connex = ft_connect_room(*rooms->connex, tmp, connect_id);
		rooms = rooms->next;
	}
	return (tmp);
}

t_room			*ft_add_connect(t_room *rooms, t_tube *tubes)
{
	while (tubes)
	{
		rooms = ft_test_tube(tubes->room1, tubes->room2, rooms);
		rooms = ft_test_tube(tubes->room2, tubes->room1, rooms);
		tubes = tubes->next;
	}
	return (rooms);
}
