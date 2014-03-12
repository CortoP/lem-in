/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:00:16 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 18:06:53 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			is_link(char *str)
{
	int			i;

	i = 0;
	while (ft_isalnum(str[i]))
		i++;
	if (str[i++] != '-')
		return (0);
	while (ft_isalnum(str[i]))
		i++;
	if (str[i++] != '\0')
		return (0);
	return (1);
}
