/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:33:05 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/18 17:38:50 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lst_push_front(t_list *list, t_list *new)
{
	new->next = list;
	return (new);
}

t_list		*ft_lst_push_back(t_list *list, t_list *new)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}
