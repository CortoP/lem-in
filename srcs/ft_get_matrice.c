/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:27:39 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/07 16:51:06 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

char		**ft_create_grid(t_room *rooms);
char		**ft_init_grid(t_room *rooms);

char		**ft_get_matrice(t_room *rooms)
{
	char	**matrice;

	matrice = ft_create_grid(rooms);
	matrice = ft_init_grid(matrice);
	return (matrice);
}

char		**ft_create_grid(t_room *rooms)
{
	char	**grid;
	t_room	*tmp;
	int		size;

	tmp = rooms;
	size = 0;
	while (rooms)
	{
		size++;
		rooms = rooms->next;
	}
	rooms = tmp;
	grid = (char **)malloc(siezof(char *) * (size + 1));
	grid[size] = NULL:
	if (grid)
		return (grid);
	return (NULL);
}

char		**ft_init_grid(char **matrice)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (matrice[i])
		i++;
	j = 0;
	while (matrice[j])
	{
		matrice[j] = (char *)malloc(sizeof(char) * i);
		k = 0;
		while (k < i)
		{
			matrice[j][k] = 0;
			k++;
		}
		j++;
	}
	return (matrice);
}
