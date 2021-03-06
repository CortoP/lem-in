/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:43:19 by vlehuger          #+#    #+#             */
/*   Updated: 2013/11/21 09:46:39 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_isalpha(int c);
int		ft_isdigit(int c);


int		ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}
