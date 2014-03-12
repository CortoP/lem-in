/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:50:05 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 15:29:12 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <libft.h> //////////////

t_state			get_room(t_lem *p, char *str)
{
	(void)p;
	if (is_room(str) == 1)
	{	
		ft_putendl(str);
		return (ROOM); //////////
	}
	if (is_command(str) == 1)
	{
		if (ft_strcmp(str, "##start") == 0)
		{
			ft_putstr("START ==> ");
		}
		else if (ft_strcmp(str, "##end") == 0)
		{
			ft_putstr("END ==> ");
		}
		return (ROOM);
	}
//	else if (is_link(str) == 1)
//	{
		return (LINK);
//	}
	error();
	return (END);
}
