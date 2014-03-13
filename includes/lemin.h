/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:08:52 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 18:45:02 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define X coord[0]
# define Y coord[1]
# define START 1
# define FINISH 2

# include <libft.h>

typedef	enum	e_state
{
	ANT,
	ROOM,
	LINK,
	END
}				t_state;

typedef struct	s_link
{
	struct s_room	*link_room;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	int				id;
	char			*str;
	char			cmd;
	int				coord[2];
	struct s_link	*link;
	struct s_room	*next;
}					t_room;

typedef struct	s_lem
{
	int			ant;
  t_list		*file;
	t_room		*room;
}				t_lem;

void		parser(t_lem *p);
t_state		get_ant(t_lem *p, char *str);
t_state		get_room(t_lem *p, char *str);
t_state		get_link(t_lem *p, char *str);

t_room		*init_room(void);
void		fill_room(t_lem *p, char *str);
void		fill_link(t_lem *p, char *str);
char		is_room(char *str);
char		is_command(char *str);
char		is_link(char *str);

void		error(void);
void		display_file(t_list *file);

#endif /* !LEMIN_H */
