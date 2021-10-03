/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 00:38:34 by mfunyu           ###   ########.fr       */
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
	int		num_rows;
	char	empty;
	char	obstacle;
	char	full;
}				t_info;

typedef struct s_tempcrs
{
	int	col;
	int	row;
	int	size;
}				t_tempcrs;

/*
** global vars
*/
extern int		g_max;
extern int		g_col;
extern int		g_row;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
int				ft_strlen(char *str);
int				ft_is_printable(char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *str, char *charset);
int				ft_atoi(char *str);
int				check_map_first_line(char *line);
t_info			*parse_first_line(char *line);
int				check_map_structure(char **map, t_info *info);
int				check_newline_at_eof(char *content);
void			set_tempcrs(t_tempcrs *p_tempcrs);
int				ft_check_1(char **map, int col, int row, t_info *p_info);
void			generate_correct_map(char **map, t_info *p_info);
void			set_bsq(t_bsq *p_bsq);
int				ft_map_colsize(char **map);

char	*read_from_fd(int fd);

#endif
