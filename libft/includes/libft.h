/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:37:06 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/25 11:47:12 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 64

#  include <string.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <fcntl.h>

typedef struct	s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				size_line;
	int				endian;
	int				bpp;
	char			*data;
}					t_env;

double		ft_atod(const char *s);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
size_t		ft_itoa_ccount(unsigned long int n);
void		ft_lstadd(t_list **alst, t_list *new);
t_list		*ft_lstnew(void const *conent, size_t content_size);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
int			ft_nb_int(char *line);
void		ft_putarray(char **array);
void		ft_putarray_fd(char **array, int fd);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
t_coord		*ft_str_to_coord(char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
t_coord		*get_coord(double x, double y, double z);
int			get_next_line(const int fd, char **line);
int			**get_grid(char **argv);
void		pixel_to_img(unsigned long img_color, t_env *e, int x, int y);

/*
** VECTORS
*/
t_coord		*ft_add_vectors(t_coord *v1, t_coord *v2);
t_coord		*ft_sub_vectors(t_coord *v1, t_coord *v2);
t_coord		*ft_mult_vector(t_coord *v, double k);
t_coord		*ft_div_vector(t_coord *v, double k);




void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));


#endif
