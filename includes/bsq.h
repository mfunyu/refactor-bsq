/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 00:58:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

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

typedef enum e_mapchars
{
	EMPTY,
	OBSTACLE,
	FULL,
	NUM_MAPCHARS
}			t_mapchars;

int		read_map_from_stdin(char **content);
int		read_map_from_file(const char *filename, char **content);

bool	is_valid_input(const char *content, t_info *info);
bool	is_valid_first_line(const char *content, t_info *info);
bool	is_valid_map_structure(const char **map, t_info *info);
bool	is_valid_chars(const char *content, t_info *info);
bool	is_valid_map_height(const char *content, t_info *info);
int		header_len(const char *content);

int		load_map_data(char ***p_map, const char *content, t_info *info);
void	solve(const char **map, t_info *p_info);
int		is_empty_spot_on_map(const char **map, int x, int y, t_info *p_info);
void	search_square(const char **map, t_coord *p_coord, t_info *p_info);
void	apply_square_on_map(char **map, const t_info *p_info);
void	put_map(const char **map, const t_info *p_info);

void	free_map(char ***map);

#endif
