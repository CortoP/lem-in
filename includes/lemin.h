/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:08:52 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/14 16:21:15 by vlehuger         ###   ########.fr       */
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
	int				ant;
	int				coord[2];
	int				weight;
	struct s_link	*link;
	struct s_room	*next;
}					t_room;

typedef struct	s_ant
{
	char			*name;
	t_room			*room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_lem
{
	int			ant;
	t_ant		*ants;
	t_list		*file;
	t_room		*room;
	t_room		*first;
	t_room		*end;
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
void		weighting(t_lem *p);
void		init_ant(t_lem *p);
void		lemin(t_lem *p);

#endif /* !LEMIN_H */
