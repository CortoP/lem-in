/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ccount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:28:21 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/22 16:21:40 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

size_t	ft_itoa_ccount(unsigned long int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		++count;
		n /= 10;
	}
	return (count);
}
