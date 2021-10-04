/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 16:43:19 by mfunyu           ###   ########.fr       */
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

typedef struct s_bsq
{
	int			x;
	int			y;
	int			size;
}				t_bsq;

typedef struct s_info
{
	int		map_height;
	int		map_width;
	char	empty;
	char	obstacle;
	char	full;
}				t_info;

typedef struct s_tempcrs
{
	int	x;
	int	y;
	int	size;
}				t_tempcrs;

/*
** global vars
*/
extern int		g_max;
extern int		g_col;
extern int		g_row;

/*
** puts
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_puterror(char *str);

int				ft_strlen(char *str);
int				ft_is_printable(char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *str, char *charset);
int				ft_atoi(char *str);
int				check_first_line(char *content, int len);
int				init_t_info(t_info *info, char **map, char *line, int len);
int				check_map_structure(char **map, t_info *info);
int				check_newline_at_eof(char *content);
void			set_tempcrs(t_tempcrs *p_tempcrs);
int				ft_check_1(char **map, int x, int y, t_info *p_info);
void			generate_correct_map(char **map, t_info *p_info);
void			set_bsq(t_bsq *p_bsq);

char	*read_from_fd(int fd);

#endif
