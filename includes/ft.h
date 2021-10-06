/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 23:23:14 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define FT_BUFSIZ 320000
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

int		read_map_from_stdin(char **content);
int		read_map_from_file(char *filename, char **content);

int		validate_input(char *content, t_info *info);
int		validate_first_line(char *content, t_info *info);
int		validate_map_structure(char **map, t_info *info);

int		load_map_data(char ***p_map, char *content, t_info *info);
void	generate_answer(char **map, t_info *p_info);
int		is_empty_spot_on_map(char **map, int x, int y, t_info *p_info);
void	search_square(char **map, t_coord *p_coord, t_info *p_info);
void	apply_square_on_map(char **map, t_info *p_info);
void	put_map(char **map, t_info *p_info);

void	free_map(char ***map);

/*
** utils
*/
int		ft_atoi(char *str);
int		ft_is_printable(char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_puterror(char *str);

char	**ft_split(char *str, char *charset);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
