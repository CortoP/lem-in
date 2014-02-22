/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tubes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:59:19 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/18 12:10:41 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				ft_affect_id(char *tubes, t_room *rooms)
{
	while (rooms)
	{
		if (ft_strcmp(tubes, rooms->name) == 0)
			return (rooms->id);
		rooms = rooms->next;
	}
	ft_error();
	return (-1);
}

t_tube			*ft_init_tubes(void)
{
	t_tube		*tube;

	tube = (t_tube *)malloc(sizeof(t_tube));
	if (tube)
	{
		tube->room1 = 0;
		tube->room2 = 0;
		tube->next = NULL;
		return (tube);
	}
	return (NULL);
}

t_tube			*ft_get_struct_tubes(t_list *l_tubes, t_room *rooms)
{
	t_tube		*tubes;
	t_tube		*tmp_t;
	char		**tmp;

	tubes = ft_init_tubes();
	tmp = ft_strsplit(l_tubes->content, '-');
	tubes->room1 = ft_affect_id(tmp[0], rooms);
	tubes->room2 = ft_affect_id(tmp[1], rooms);
	l_tubes = l_tubes->next;
	tmp_t = tubes;
	while (l_tubes)
	{
		free(tmp);
		tubes->next = ft_init_tubes();
		tmp = ft_strsplit(l_tubes->content, '-');
		tubes->next->room1 = ft_affect_id(tmp[0], rooms);
		tubes->next->room2 = ft_affect_id(tmp[1], rooms);
		l_tubes = l_tubes->next;
		tubes = tubes->next;
	}
	free(tmp);
	return (tmp_t);
}
