/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:50:05 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 19:12:42 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <libft.h>

static void		fill_cmd(char *str, t_lem *p)
{
	t_room		*room;

	if (ft_strcmp(str, "##start") == 0)
	{
		room = init_room();
		room->cmd = START;
		if (p->room)
			room->next = p->room;
		p->room = room;
	}
	else if (ft_strcmp(str, "##end") == 0)
	{
		room = init_room();
		room->cmd = FINISH;
		if (p->room)
			room->next = p->room;
		p->room = room;
	}
}

t_state			get_room(t_lem *p, char *str)
{
	if (is_room(str) == 1)
	{
		fill_room(p, str);
		return (ROOM);
	}
	else if (is_command(str) == 1)
	{
		fill_cmd(str, p);
		return (ROOM);
	}
	else if (is_link(str) == 1)
		return (get_link(p, str));
	error();
	return (END);
}
