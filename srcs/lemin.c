/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:58:02 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/23 12:57:41 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			main(void)
{
	t_lm	*params;
	t_room	*rooms;
	t_tube	*tubes;

	params = ft_parser();
	rooms = ft_get_rooms_struct(params->rooms);
	tubes = ft_get_struct_tubes(params->tubes, rooms);
	rooms = ft_add_connect(rooms, tubes);
	rooms = ft_weighting(rooms);
	while (*params->file)
	{
		if (ft_strcmp((*params->file)->content, "") != 0)
			ft_putendl((*params->file)->content);
		*params->file = (*params->file)->next;
	}
	ft_putchar('\n');
	ft_solve(rooms, params->ant_nb);
	return (0);
}
