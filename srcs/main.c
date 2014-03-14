/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:46:16 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 16:24:29 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	init_lem(t_lem *p)
{
	p->room = NULL;
	p->ants = NULL;
	p->file = NULL;
}

int			main(void)
{
	t_lem	param;

	init_lem(&param);
	parser(&param);
	weighting(&param);
	init_ant(&param);
	display_file(param.file);
	ft_putchar('\n');
//	ft_putnbr(param.ants->room->link->link_room->ant);
//	ft_putchar('\n');
	lemin(&param);
	return (0);
}



/*		link
**
**	while (param.room)
**	{
**		ft_putstr(param.room->str);
**		ft_putstr(" ==> ");
**		while (param.room->link)
**		{
**			ft_putstr(param.room->link->link_room->str);
**			param.room->link = param.room->link->next;
**		}
**		ft_putchar('\n');
**		param.room = param.room->next;
**	}
*/



/*		weights
**
**	while (param.room)
**	{
**		ft_putstr(param.room->str);
**		ft_putstr(" ==> ");
**		ft_putnbr(param.room->weight);
**		ft_putchar('\n');
**		param.room = param.room->next;
**	}
*/

/*		ants
**
**	while (param.ants)
**	{
**		ft_putendl(param.ants->name);
**		param.ants = param.ants->next;
**	}
*/
