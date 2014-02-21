/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:58:02 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/18 15:05:08 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			main(void)
{
	t_lm	*params;
	t_room	*rooms;
	t_tube	*tubes;

	params = ft_parser();
	rooms = ft_get_rooms_struct(params->rooms);
	tubes = ft_get_struct_tubes(params->tubes, rooms);
      	rooms = ft_add_connect(rooms, tubes);
       	rooms = ft_weighting(rooms);



	//		PUT THE CONNEXIONS
       	t_room *tmp;
	t_room *tmp2;
	t_room *tmp3;

	tmp = rooms;
	while (rooms)
	  {
	    printf("== %s ==\n", rooms->name);
	    tmp2 = *rooms->connex;
	    while (*rooms->connex)
	      {
		printf("%s => ", (*rooms->connex)->name);


	      	tmp3= *(*rooms->connex)->connex;
		while (*(*rooms->connex)->connex)
		  {
		    printf("%s ", (*(*rooms->connex)->connex)->name);
		    *(*rooms->connex)->connex = (*(*rooms->connex)->connex)->next;
		  }
		printf("\n");
		*(*rooms->connex)->connex = tmp3;


		*rooms->connex = (*rooms->connex)->next;
	      }
	    *rooms->connex = tmp2;
	    printf("\n");
	    rooms = rooms->next;
	  }
	rooms = tmp;

	//	ft_solve(rooms, params->ant_nb);
	return (0);
}

/*		PUT THE ROOMS

	while (rooms)
	{
		ft_putnbr(rooms->id);
		ft_putchar('\n');
		printf("%d\n", rooms->dist); 
		ft_putnbr(rooms->flag);
		ft_putchar('\n');
		ft_putendl(rooms->name);
		rooms = rooms->next;
	}
*/

/*		PUT THE TUBES
	while (tubes)
	{
		printf("%d\n%d\n\n", tubes->room1, tubes->room2);
		tubes = tubes->next;
	}

*/

/*		PUT THE CONNECTIONS
	while (rooms)
	{
		printf("%s: ", rooms->name);
		while (rooms->connex)
		{
			printf("%s ", rooms->connex->name);
			rooms->connex = rooms->connex->next;
		}
		printf("\n");
		rooms = rooms->next;
	}
*/

/*		PUT THE WEIGHT
	while (rooms)
	{
		printf("%s  => %d\n", rooms->name, *rooms->dist);
		rooms = rooms->next;
	}
*/
