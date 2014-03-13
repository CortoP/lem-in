
#include <libft.h>
#include <lemin.h>

void		display_file(t_list *file)
{
  while (file)
    {
      if (file->content_size == 1)
	{
	  ft_putstr("\033[31m");
	  ft_putendl(file->content);
	  ft_putstr("\033[00m");
	}
      else
	ft_putendl(file->content);
      free(file->content);
      file = file->next;
    }
}
