/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:58:44 by vlehuger          #+#    #+#             */
/*   Updated: 2013/11/20 15:01:37 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar_fd('-', fd);
	}
	if (nb < 10)
	{
		ft_putchar_fd('0' + nb, fd);
	}
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd('0' + (nb % 10), fd);
	}
}
