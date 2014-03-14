/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weighting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:19:08 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 16:17:20 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <stdlib.h>

static void		ft_weighting(t_room *room, int weight)
{
	t_link		*tmp;

	if (room->weight == -1 || room->weight > weight)
	{
		room->weight = weight;
		tmp = room->link;
		while (room->link)
		{
			ft_weighting(room->link->link_room, weight + 1);
			room->link = room->link->next;
		}
		room->link = tmp;
	}
}

static t_room	*find_room(t_room *room, char cmd)
{
	t_room		*save;
	t_room		*ret;

	ret = NULL;
	save = room;
	while (room)
	{
		if (room->cmd == cmd && ret == NULL)
			ret = room;
		else if (room->cmd == cmd && ret != NULL)
			error();
		room = room->next;
	}
	room = save;
	if (ret == NULL)
		error();
	return (ret);
}

void			weighting(t_lem *p)
{
	p->end = find_room(p->room, FINISH);
	//en recursive affecter une ponderation aux salles 
	ft_weighting(p->end, 0);
	p->first = find_room(p->room, START);
	if (p->first->weight == -1)
		error();
	p->first->ant = p->ant;
}
