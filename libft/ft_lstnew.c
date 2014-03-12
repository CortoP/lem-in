/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:53:11 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/11 12:21:56 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_el;

	new_el = malloc(sizeof(t_list));
	if (new_el)
	{
		if (content != NULL)
		{
			new_el->content = (void *)content;
			new_el->content_size = content_size;
			new_el->next = NULL;
		}
		else
		{
			new_el->content = NULL;
			new_el->content_size = 0;
		}
		return (new_el);
	}
	else
		return (NULL);
}
