/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 13:59:58 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 15:17:40 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
#include <libft.h>

t_state			get_ant(t_lem *p, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '#')
			return (ANT);
		if (ft_isdigit(str[i]) == 0)
		{
			error();
			return (END);
		}
		i++;
	}
	p->ant = ft_atoi(str);
//	ft_putnbr(p->ant);
//	ft_putchar('\n');
	return (ROOM);
}
