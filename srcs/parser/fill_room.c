/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:37:32 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 19:08:39 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <libft.h>

static void	fill_tmp(t_room *room, int id, char *str)
{
	char		**split;

	split = ft_strsplit(str, ' ');
	room->id = id;
	room->str = ft_strdup(split[0]);
	free(split[0]);
	room->X = ft_atoi(split[1]);
	free(split[1]);
	room->Y = ft_atoi(split[2]);
	free(split[2]);
	free(split);
}

void		fill_room(t_lem *p, char *str)
{
	t_room		*room;
	static int	id = 0;

	if (!(room = init_room()))
		error();
	fill_tmp(room, id, str);
	if (p->room == NULL)
		p->room = room;
	else if (p->room->cmd != -1 && p->room->str == NULL)
	{
		p->room->id = room->id;
		p->room->str = ft_strdup(room->str);
		p->room->X = room->X;
		p->room->Y = room->Y;
		free(room);
	}
	else
	{
		room->next = p->room;
		p->room = room;
	}
}
