/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 11:47:59 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/12 19:12:29 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

static void		ft_add(t_list *list, t_list *add)
{
  t_list	*tmp;
  
  tmp = list;
  while (list->next)
      list = list->next;
  list->next = add;
  list = tmp;
}

static void		list(t_lem *p, char *str, int flag)
{
  t_list	*list;
  
  list = ft_lstnew(str, flag);
  if (p->file == NULL)
    p->file = list;
  else
    ft_add(p->file, list);
}

void			parser(t_lem *p)
{
	char			*str;
	static t_state	state = ANT;

	while (get_next_line(0, &str) > 0)
	{
	  if (state == END)
	    list(p, str, 1);
	  else
	    list(p, str, 0);
		if (str[0] != '#' || (str[0] == '#' && str[1] == '#'))
		{
			if (state == ANT)
				state = get_ant(p, str);
			else if (state == ROOM)
				state = get_room(p, str);
			else if (state == LINK)
				state = get_link(p, str);
			free(str);
		}
	}
}
