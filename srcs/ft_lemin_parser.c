/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:33:52 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/04 16:18:20 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		ft_get_ant_nb(void);
static t_list	*ft_get_rooms(char **first_tube);
static t_list   *ft_get_tubes(char *first);
static t_list   *ft_create_tubes(char *str, t_list *tubes);

t_lm			*ft_parser(void)
{
	t_lm		*params;
	char		*first_tube;

	params = ft_init_lm();
	if (params)
	{
		params->ant_nb = ft_get_ant_nb();
		params->rooms = ft_get_rooms(&first_tube);
		params->tubes = ft_get_tubes(first_tube);
		return (params);
	}
	return (NULL);
}

static int		ft_get_ant_nb(void)
{
	char		*str;
	int			i;

	get_next_line(0, &str);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

static t_list	*ft_get_rooms(char **first_tube)
{
	t_list		*rooms;
	char		*str;

	rooms = NULL;
	while (get_next_line(0, &str) > 0)
	{
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

static t_list	*ft_get_tubes(char *first)
{
	t_list		*tubes;
	char		*str;

	tubes = ft_lstnew((char *)first, ft_strlen(first));
	ft_putendl(tubes->content);
	while (get_next_line(0, &str) > 0)
	{
		if (ft_test_room(str) != 0)
		{
			if (!(tubes = ft_create_tubes(str, tubes)))
				break ;
		}
		else if (str[0] == '#' && str[1] && str[1] != '#')
			str[0] = str[1];
		else
			break ;
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
