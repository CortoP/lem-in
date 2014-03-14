/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 17:49:58 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 14:51:06 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_state			get_link(t_lem *p, char *str)
{
	if (is_link(str) == 1)
	{
		fill_link(p, str);
		return (LINK);
	}
	else if (is_command(str) == 1)
		return (LINK);
	return (END);
}
