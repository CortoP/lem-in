/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rooms_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 16:38:41 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/23 12:38:38 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_ROOMS_STRUCT_H
# define FT_GET_ROOMS_STRUCT_H

# include <lemin.h>

t_room				*ft_get_rooms_struct(t_list *l_rooms);
t_room				*ft_create_room(int flag, char *name);

#endif /* !FT_GET_ROOMS_STRUCT_H */
