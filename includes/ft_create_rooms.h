/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rooms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:58:59 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/04 15:00:40 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CREATE_ROOMS_H
# define FT_CREATE_ROOMS_H

# include <lemin.h>

t_list			*ft_create_rooms(char *str, t_list *rooms);
int				ft_test_room(char *str);

#endif /* !FT_CREATE_ROOMS_H */
