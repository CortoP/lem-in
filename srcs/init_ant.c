/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:44:05 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 15:57:40 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>
#include <stdlib.h>

static t_ant	*create_ant(t_room *start)
{
	t_ant		*ant;
	static int	i = 1;

	ant = (t_ant *)malloc(sizeof(t_ant));
	if (ant)
	{
		ant->name = ft_strjoin("L", ft_itoa(i++));
		ant->room = start;
		ant->next = NULL;
		return (ant);
	}
	error();
	return (NULL);
}

static void		add_ant(t_lem *p)
{
	t_ant		*save;

	save = p->ants;
	while (p->ants->next)
		p->ants = p->ants->next;
	p->ants->next = create_ant(p->first);
	p->ants = save;
}

void			init_ant(t_lem *p)
{
	int		i;

	i = 1;
	while (i <= p->ant)
	{
		if (!p->ants)
			p->ants = create_ant(p->first);
		else
			add_ant(p);
		i++;
	}
}
