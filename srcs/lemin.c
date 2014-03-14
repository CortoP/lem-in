/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:23:11 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 16:44:23 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

void			go_ant(t_ant *ant)
{
	t_room		*saver;
	t_link		*savel;
	char		flag;

	flag = 0;
	saver = ant->room;
	savel = saver->link;
	while (saver->link)
	{
		if (saver->link->link_room->weight < saver->weight)
		{
			saver->ant = saver->ant - 1;
			saver->link->link_room->ant = saver->link->link_room->ant + 1;
			if (ant->room->cmd == START && ant->room->ant == 0)
				flag = 1;
			ant->room = saver->link->link_room;
			ft_putstr(ant->name);
			ft_putchar('-');
			ft_putstr(ant->room->str);
			ft_putchar(' ');
			if (flag == 1)
				ft_putchar('\n');
			break ;
		}
		saver->link = saver->link->next;
	}
	saver->link = savel;
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

void			lemin(t_lem *p)
{
	t_ant		*save;

	while (p->ant > 0)
	{
		save = p->ants;
		while (p->ants)
		{
			if (is_moovable(p->ants) == 0)	//test si la fourmi peut bouger
			{
				ft_putchar('\n');
				break ;
			}
			go_ant(p->ants); //fait bouger la fourmi et les compteurs des 2 salles
			if (p->ants->room == p->end)
			{
				free(p->ants->name);
				save = save->next;
				p->end->ant -= 1;
				p->ant -= 1;
			}
			p->ants = p->ants->next;
		}
		p->ants = save;
	}
	ft_putchar('\n');
}