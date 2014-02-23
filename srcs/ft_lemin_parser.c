/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:33:52 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/23 12:15:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		ft_get_ant_nb(t_list **file);
static t_list	*ft_get_rooms(char **first_tube, t_list **file);
static t_list   *ft_get_tubes(char *first, t_list **file);
static t_list   *ft_create_tubes(char *str, t_list *tubes);

t_lm			*ft_parser(void)
{
	t_lm		*params;
	char		*first_tube;

	params = ft_init_lm();
	if (params)
	{
	  if ((params->ant_nb = ft_get_ant_nb(params->file)) == -1)
	    ft_error();
	  params->rooms = ft_get_rooms(&first_tube, params->file);
	  params->tubes = ft_get_tubes(first_tube, params->file);
		return (params);
	}
	return (NULL);
}

static int		ft_get_ant_nb(t_list **file)
{
	char		*str;
	int			i;

	get_next_line(0, &str);
	*file = ft_lstnew(str, 0);
	i = 0;
	if (str[i])
	  {
	    
	    while (str[i])
	      {
		if (ft_isdigit(str[i]) == 0)
		  return (-1);
		i++;
	      }
	    return (ft_atoi(str));
	  }
	return (-1);
}

static t_list	*ft_get_rooms(char **first_tube, t_list **file)
{
	t_list		*rooms;
	char		*str;

	rooms = NULL;
	while (get_next_line(0, &str) > 0)
    {
		*file = ft_lst_push_back(*file, ft_lstnew(str, 0));
		if (!str[0])
			ft_error();
		if (ft_test_room(str) == 0)
		{
			if (!(rooms = ft_create_rooms(str, rooms)))
				break ;
	    }
		else
	break ;
    }
	if (rooms && (*first_tube = ft_strdup(str)))
    {
		free(str);
		return (rooms);
    }
  return (NULL);
}

static t_list	*ft_get_tubes(char *first, t_list **file)
{
	t_list		*tubes;
	char		*str;

	tubes = ft_lstnew((char *)first, ft_strlen(first));
	*file = ft_lst_push_back(*file, ft_lstnew(first, 0));
	while (get_next_line(0, &str) > 0)
	{
		(void)file;
		*file = ft_lst_push_back(*file, ft_lstnew(str, 0));
		if (!str[0])
			ft_error();
		if (ft_test_room(str) != 0)
		{
			if (!(tubes = ft_create_tubes(str, tubes)))
				break ;
		}
		else if (str[0] == '#' && str[1] && str[1] != '#')
			str[0] = str[1];
		else
			ft_error();
	}
	return (tubes);
}

static t_list	*ft_create_tubes(char *str, t_list *tubes)
{
	t_list		*tmp;

	tmp = tubes;
	while (tubes->next)
		tubes = tubes->next;
	if ((tubes->next = ft_lstnew((char *)str, ft_strlen(str))))
		return (tmp);
	return (NULL);
}
