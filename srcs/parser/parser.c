/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:47:59 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 19:12:29 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

void			parser(t_lem *p)
{
	char			*str;
	static t_state	state = ANT;

	while (get_next_line(0, &str) > 0)
	{
		//creation de la liste chainee
		if (str[0] != '#' || (str[0] == '#' && str[1] == '#'))
		{
			if (state == ANT)
				state = get_ant(p, str);
			else if (state == ROOM)
				state = get_room(p, str);
			else if (state == LINK)
				state = get_link(p, str);
			free(str); /////////////////
		}
	}
}
