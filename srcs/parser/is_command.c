/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:16:37 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 15:17:57 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		is_command(char *str)
{
	if (str[1] && str[1] == '#')
		return (1);
	else
		return (0);
}
