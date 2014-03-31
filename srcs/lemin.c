/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:23:11 by vlehuger          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/03/17 11:19:49 by vlehuger         ###   ########.fr       */
=======
/*   Updated: 2014/03/15 13:39:08 by vlehuger         ###   ########.fr       */
>>>>>>> c8da24de8dc66a9a812749f497f26bbc3e8e8643
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>
#include <stdio.h>

char			is_moovable(t_ant *ant);

char			is_spaceable(t_ant *ant)
{
	t_ant		*save;
	int			ret;

	ret = 0;
	save = ant;
	while (ant)
	{
		if (is_moovable(ant) == 1)
		{
			ret = 1;
			break ;
		}
		ant = ant->next;
	}
	ant = save;
	return (ret);
}

char			is_moovable(t_ant *ant)
{
	t_link		*link;
	char		ret;

	ret = 0;
	link = ant->room->link;
	while (ant->room->link)
	{
		if (ant->room->link->link_room->weight < ant->room->weight
			&& ant->room->link->link_room->ant == 0)
		{
			ret = 1;
			break ;
		}
		ant->room->link = ant->room->link->next;
	}
	ant->room->link = link;
	return (ret);
}

void			display_ant(t_ant *ant, char flag)
{
	ft_putstr(ant->name);
	ft_putchar('-');
	ft_putstr(ant->room->str);
	if (ant->next && is_moovable(ant->next) == 1)
		ft_putchar(' ');
	if (flag == 1)
		ft_putchar('\n');	
}

void			go_ant(t_ant *ant)
{
	t_room		*saver;
	t_link		*savel;

	saver = ant->room;
	savel = saver->link;
	while (saver->link)
	{
		if (saver->link->link_room->weight < saver->weight && saver->link->link_room->ant == 0)
		{
			saver->ant = saver->ant - 1;
			saver->link->link_room->ant = saver->link->link_room->ant + 1;
			ant->room = saver->link->link_room;
<<<<<<< HEAD
			ft_putstr(ant->name);
			ft_putchar('-');
			ft_putstr(ant->room->str);
//			if ((ant->next && is_moovable(ant->next) == 1) || (ant->next && ant->next->next && is_moovable(ant->next->next) == 1))
			if (ant->next && is_spaceable(ant->next) == 1)
				ft_putchar(' ');
=======
			display_ant(ant, flag);
>>>>>>> c8da24de8dc66a9a812749f497f26bbc3e8e8643
			break ;
		}
		saver->link = saver->link->next;
	}
	saver->link = savel;
}

void			lemin(t_lem *p)
{
	t_ant		*save;
//	t_room		*saveroom;/////////////////////////

	while (p->ant > 0)
	{
		save = p->ants;
		while (p->ants)
		{
<<<<<<< HEAD
/*
			saveroom = p->room;
			while (p->room)
=======
			if (is_moovable(p->ants) == 0)
>>>>>>> c8da24de8dc66a9a812749f497f26bbc3e8e8643
			{
				printf("%s ==> %s -> %d\n", p->ants->name, p->room->str, p->room->ant);
				p->room = p->room->next;
			}
<<<<<<< HEAD
			p->room = saveroom;
*/
			if (is_moovable(p->ants) == 1)	//test si la fourmi peut bouger
=======
			go_ant(p->ants);
			if (p->ants->room == p->end)
>>>>>>> c8da24de8dc66a9a812749f497f26bbc3e8e8643
			{
				go_ant(p->ants); //fait bouger la fourmi et les compteurs des 2 salles
				if (p->ants->room == p->end)
				{
					free(p->ants->name);
					save = save->next;
					p->end->ant -= 1;
					p->ant -= 1;
				}
			}
			p->ants = p->ants->next;
		}
		ft_putchar('\n');
		p->ants = save;
	}
}
