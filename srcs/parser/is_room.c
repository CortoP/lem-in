/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:00:16 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 15:21:37 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

char		is_room(char *str)
{
	int		i;

	i = 0;
	while (ft_isalnum(str[i]) == 1)
		i++;
	if (str[i++] != ' ')
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i++] != ' ')
		return (0);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
