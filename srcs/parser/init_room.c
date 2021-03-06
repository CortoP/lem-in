/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:29:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 15:26:26 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <stdlib.h>

t_room			*init_room(void)
{
	t_room		*room;

	room = (t_room *)malloc(sizeof(t_room));
	if (room)
	{
		room->id = -1;
		room->ant = 0;
		room->str = NULL;
		room->cmd = -1;
		room->X = 0;
		room->Y = 0;
		room->link = NULL;
		room->next = NULL;
		room->weight = -1;
		return (room);
	}
	return (NULL);
}
