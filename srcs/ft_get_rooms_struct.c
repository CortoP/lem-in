/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rooms_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 16:28:28 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/18 14:52:21 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static t_room		*ft_get_room(t_list *l_room, t_room *rooms);
static t_room		*ft_add_room(t_room *rooms, t_list *l_room);

t_room				*ft_get_rooms_struct(t_list *l_rooms)
{
	t_room			*rooms;
	char			*tmp;

	rooms = NULL;
	while (l_rooms)
	{
		rooms = ft_get_room(l_rooms, rooms);
		tmp = ft_strdup(l_rooms->content);
		if (tmp[0] == '#')
			l_rooms = l_rooms->next;
		l_rooms = l_rooms->next;
		free(tmp);
	}
	return (rooms);
}

static t_room		*ft_get_room(t_list *l_room, t_room *rooms)
{
	char			*tmp;

	tmp = NULL;
	if (!rooms)
	{
		tmp = ft_strdup(l_room->content);
		if (tmp[0] == '#')
		{
			if (ft_strcmp(l_room->content, "##start") == 0 && l_room->next)
				rooms = ft_create_room(START, l_room->next->content);
			else if (ft_strcmp(l_room->content, "##end") == 0 && l_room->next)
				rooms = ft_create_room(END, l_room->next->content);
			else
				return (NULL);
		}
		else
			rooms->next = ft_create_room(0, l_room->content);
	}
	else
	{
		rooms = ft_add_room(rooms, l_room);
	}
	if (tmp)
		free(tmp);
	return (rooms);
}

t_room				*ft_create_room(int flag, char *name)
{
	t_room			*room;
	static int		id = 0;

	room = (t_room *)malloc(sizeof(t_room));
	if (room)
	{
		room->id = id;
		room->dist = (int *)malloc(sizeof(int));
		*room->dist = -1;
		room->flag = flag;
		room->name = ft_strdup(ft_get_first_word(name));
		room->ant = (int *)malloc(sizeof(int));
		*room->ant = 0;
		room->connex = NULL;
		room->next = NULL;
		id++;
		return (room);
	}
	return (NULL);
}

static t_room		*ft_add_room(t_room *rooms, t_list *l_room)
{
	t_room			*tmp;
	char			*str_tmp;

	str_tmp = ft_strdup(l_room->content);
	tmp = rooms;
	while (rooms->next)
		rooms = rooms->next;
	if (str_tmp[0] == '#')
	{
		if (ft_strcmp(l_room->content, "##start") == 0 && l_room->next)
			rooms->next = ft_create_room(START, l_room->next->content);
		else if (ft_strcmp(l_room->content, "##end") == 0 && l_room->next)
			rooms->next = ft_create_room(END, l_room->next->content);
		else
			rooms->next = NULL;
	}
	else
		rooms->next = ft_create_room(0, l_room->content);
	free(str_tmp);
	return (tmp);
}
