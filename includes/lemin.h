/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:08:52 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 15:26:10 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define coord[0] X
# define coord[1] Y

typedef	enum	e_state
{
	ANT,
	ROOM,
	LINK,
	END
}				t_state;

struct			s_room
{
	int			id;
	char		*str;
	int			coord[2];
	s_room		*link;
	s_room		*next;
}				t_room;

typedef struct	s_lem
{
	int			ant;
}				t_lem;

void		parser(t_lem *p);
t_state		get_ant(t_lem *p, char *str);
t_state		get_room(t_lem *p, char *str);

char		is_room(char *str);
char		is_command(char *str);

void		error(void);

#endif /* !LEMIN_H */
