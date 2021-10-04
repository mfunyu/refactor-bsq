/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 23:25:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libgen.h>

# define FT_BUFSIZ 320000
# define IN 1
# define OUT 0
# define SUCCESS 1
# define FAIL 0
# define FT_ERR_MAP "map error\n"

typedef struct s_info
{
	int		map_height;
	int		map_width;
	char	empty;
	char	obstacle;
	char	full;
	int		max_sq_size;
	int		sq_x_coord;
	int		sq_y_coord;
}				t_info;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

int				check_first_line(char *content, int len);
int				init_t_info(t_info *info, char **map, char *line, int len);
int				check_map_structure(char **map, t_info *info);
int				check_newline_at_eof(char *content);
void			set_coord(t_coord *p_coord);
int				is_empty_spot_on_map(char **map, int x, int y, t_info *p_info);
void			generate_answer(char **map, t_info *p_info);

char	*read_from_fd(int fd);

void	put_map(char **map, t_info *p_info);

/*
** utils
*/
int				ft_atoi(char *str);
int				ft_is_printable(char c);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_puterror(char *str);

char			**ft_split(char *str, char *charset);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);

#endif
