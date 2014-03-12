/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:29:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 15:33:23 by vlehuger         ###   ########.fr       */
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
		id = -1;
		str = NULL;
		X = 0;
		Y = 0;
		link = NULL;
		next = NULL;
		return (room);
	}
	return (NULL);
}
