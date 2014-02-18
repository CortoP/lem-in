/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_first_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:29:15 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/07 14:36:55 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

char		*ft_get_first_word(char *str)
{
	char	*word;
	char	**clipped_str;

	if (!(clipped_str = ft_strsplit(str, ' ')))
		return (NULL);
	if (!clipped_str[0])
		return (NULL);
	else
	{
		word = ft_strdup(clipped_str[0]);
		free(clipped_str);
		return (word);
	}
}
