/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:24:24 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/22 16:24:25 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_strdel(char **as)
{
	if (as)
		ft_memdel((void *) &*as);
}
