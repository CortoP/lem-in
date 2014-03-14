/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:46:16 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 15:03:43 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void	init_lem(t_lem *p)
{
	p->room = NULL;
	p->file = NULL;
}

int			main(void)
{
	t_lem	param;

	init_lem(&param);
	parser(&param);

	while (param.room)
	{
		ft_putstr(param.room->str);
		ft_putstr(" ==> ");
		while (param.room->link)
		{
			ft_putstr(param.room->link->link_room->str);
			param.room->link = param.room->link->next;
		}
		ft_putchar('\n');
		param.room = param.room->next;
	}




//	weighting(&param);
//	display_file(param.file);
//	lemin();
	return (0);
}
