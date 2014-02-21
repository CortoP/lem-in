/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:53:10 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/18 16:21:23 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void			ft_move_ants(t_room *room)
{
	t_room		**tmp;

	tmp = room->connex;
	while (room->connex && *room->ant > 0)
	{
	  if (*(*room->connex)->ant == 0 || (*room->connex)->flag == END) && *room->dist > *(*room->connex)->dist)
		{
			*room->ant = *room->ant - 1;
			*(*room->connex)->ant = *(*room->connex)->ant + 1;
		}
		*room->connex = (*room->connex)->next;
	}
	room->connex = tmp;
}



t_room			*ft_affect_first_ant(t_room *rooms, int ants)
{
	while (rooms)
	{
		if (rooms->flag == START)
		{
			*rooms->ant = ants;
			return (rooms);
		}
		rooms = rooms->next;
	}
	return (NULL);
}

void			ft_solve(t_room *rooms, int ants)
{
	t_room		*tmp;
	int			i;


	tmp = rooms;
	rooms = ft_affect_first_ant(rooms, ants);
	while (rooms)
	{
		printf("%s ants = %d\n", rooms->name, *rooms->ant); 
		rooms = rooms->next;
	}
	rooms = tmp;
	printf("\n\n");
	i = 0;
	while (i < 50)
	{
		rooms = tmp;
		while (rooms)
		{
			ft_move_ants(rooms);
		rooms = rooms->next;
		}
		i++;
	}

//		PUT THE ANTS NB PER ROOM 
	rooms = tmp;
	while (rooms)
	{
		printf("%s ants = %d\n", rooms->name, *rooms->ant); 
		rooms = rooms->next;
	}
}

