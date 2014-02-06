/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:44:07 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/04 15:03:25 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_lm		*ft_init_lm(void)
{
	t_lm	*params;

	params = (t_lm*)malloc(sizeof(t_lm));
	if (params)
	{
		params->ant_nb = 0;
		params->ants = NULL;
		params->room_nb = 0;
		params->rooms = NULL;
		params->tube_nb = 0;
		params->tubes = NULL;
		return (params);
	}
	return (NULL);
}
