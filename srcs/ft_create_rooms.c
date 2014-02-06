/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:38:51 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/04 15:17:17 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_list			*ft_create_rooms(char *str, t_list *rooms)
{
	t_list		*tmp;

	if (!rooms)
	{
		rooms = ft_lstnew((char *)str, ft_strlen(str));
		return (rooms);
	}
	else
	{
		tmp = rooms;
		while (rooms->next)
			rooms = rooms->next;
		rooms->next = ft_lstnew((char *)str, ft_strlen(str));
		return (tmp);
	}
}

int				ft_test_room(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i] == '-')
		return (i);
	else
		return (0);
}
