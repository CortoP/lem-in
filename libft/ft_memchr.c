/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:52:42 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 11:54:08 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	if (s == NULL)
		return (NULL);
	t = (unsigned char *)s;
	i = 0;
	while (i < n && t[i])
	{
		if (t[i] == (unsigned char)c)
			return (t + i);
		i++;
	}
	return (NULL);
}
