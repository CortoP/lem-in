/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:11:11 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 15:14:57 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <stdlib.h>
#include <libft.h>

t_link			*init_link(void)
{
	t_link		*link;

	link = (t_link *)malloc(sizeof(t_link));
	if (link)
	{
		link->link_room = NULL;
		link->next = NULL;
		return (link);
	}
	error();
	return (NULL);
}

static void		links(t_room *room, t_room *linked)
{
	t_link		*link;

	link = init_link();
	link->link_room = linked;
	if (room->link == NULL)
		room->link = link;
	else
	{
		link->next = room->link;
		room->link = link;
	}
}

static void		create_link(t_room *room, char **split)
{
	t_room		*tmp[2];

	tmp[0] = room;
	while (room)
	{
		if (ft_strcmp(room->str, split[0]) == 0)
		{
			tmp[1] = tmp[0];
			while (tmp[1])
			{
				if (ft_strcmp(tmp[1]->str, split[1]) == 0)
				{
					links(room, tmp[1]);
					links(tmp[1], room);
					break ;
				}
				tmp[1] = tmp[1]->next;
			}
			(tmp[1] == NULL) ? error() : (void)split;
			break ;
		}
		room = room->next;
	}
	(room == NULL) ? error() : (void)split;
	room = tmp[0];
}

void			fill_link(t_lem *p, char *str)
{
	char		**split;

	split = ft_strsplit(str, '-');
	create_link(p->room, split);
	free (split[0]);
	free (split[1]);
	free(split);
}
