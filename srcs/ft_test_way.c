
#include <lemin.h>

int		ft_test(int c)
{
  static int	  tab[1000] = {0};
  int		  i;
  
  i = 0;
  while (tab[i])
    {
      if (tab[i] == c)
	return (1);
      i++;
    }
  tab[i] = c;
  tab[i + 1] = 0;
  return (0);
}



int		ft_test_way(t_room *start)
{
  t_room	*tmp;

  tmp = *start->connex;
  while (*start->connex)
    {
      if ((*start->connex)->flag == END)
	{
	  *start->connex = tmp;
	  return (1);
	}
      
      if ((*start->connex)->flag != START)
	{
	  
	  if (ft_test((*start->connex)->id) == 0 && ft_test_way(*start->connex) == 1)
	  {
	    *start->connex = tmp;
	    return (1);
	  }
	}
      *start->connex = (*start->connex)->next;
    }
  *start->connex = tmp;
  if (start->flag == START)
    ft_error();
  return (0);
}
