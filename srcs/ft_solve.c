/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:53:10 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/23 12:46:18 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			ft_ant_swap(t_room *room, t_room *connex)
{
	t_list		*tmp;
	t_list		*room_ants;

	room_ants = *room->ant;
	tmp = NULL;
	while ((*room->ant)->next)
	{
		tmp = *room->ant;
		*room->ant = (*room->ant)->next;
	}
	ft_putstr((*room->ant)->content);
	ft_putchar('-');
	ft_putstr(connex->name);
	ft_putchar(' ');
	if (connex->flag == END)
		*connex->end_ants = *connex->end_ants + 1;
	else
		*connex->ant = *room->ant;
	if (tmp == NULL)
		*room->ant = NULL;
	else
	{
		*room->ant = room_ants;
		tmp->next = NULL;
	}
}

t_list			*ft_create_ant_list(int nb)
{
	t_list		*list;

	list = NULL;
	while (nb > 0)
	{
		if (!list)
			list = ft_lstnew(ft_strjoin("L", ft_itoa(nb)), nb);
		else
			list = ft_lst_push_back(list,
									ft_lstnew(ft_strjoin("L",
														 ft_itoa(nb)), nb));
		nb--;
	}
	return (list);
}

t_room			*ft_affect_first_ant(t_room *rooms, int ants)
{
	while (rooms)
	{
		if (rooms->flag == START)
			break ;
		rooms = rooms->next;
	}
	*rooms->ant = ft_create_ant_list(ants);
	return (rooms);
}

int				*ft_get_end_ants(t_room *rooms)
{
	t_room		*tmp;
	int			*ret;

	tmp = rooms;
	while (rooms)
	{
		if (rooms->flag == END)
			ret = rooms->end_ants;
		rooms = rooms->next;
	}
	rooms = tmp;
	return (ret);
}

void			ft_solve(t_room *rooms, int ants)
{
	t_room		*start;
	t_room		*tmp;
	int			*end;

	end = ft_get_end_ants(rooms);
	start = ft_affect_first_ant(rooms, ants);
	ft_test_way(start);
	while (*end < ants)
	{
		if (*start->ant)
		{
			start = ft_move_start(start);
			ft_putchar('\n');
		}
		else
		{
			tmp = rooms;
			while (rooms && *end < ants)
			{
				rooms = ft_move(rooms);
				rooms = rooms->next;
			}
			rooms = tmp;
		}
	}
}
