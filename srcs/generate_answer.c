/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 23:16:25 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_max;
int		g_col;
int		g_row;

int	is_square_placable(char **map, t_coord *p_coord, int sq_size, t_info *p_info)
{
	int	i;

	i = 0;
	while (i <= sq_size)
	{
		if (!is_empty_spot_on_map(map, p_coord->x + i,
			p_coord->y + sq_size, p_info))
			return (0);
		i++;
	}
	i = 0;
	while (i <= sq_size)
	{
		if (!is_empty_spot_on_map(map, p_coord->x + sq_size,
				p_coord->y + i, p_info))
			return (0);
		i++;
	}
	return (1);
}

void	check_for_square(char **map, t_coord *p_coord, t_info *p_info)
{
	int	sq_size;

	sq_size = 0;
	while (is_square_placable(map, p_coord, sq_size, p_info))
	{
		sq_size++;
	}
	if (g_max < sq_size)
	{
		g_max = sq_size;
		g_col = p_coord->x;
		g_row = p_coord->y;
	}
}

void	ft_change_map(char **map, t_info *p_info)
{
	int		x;
	int		y;

	y = 0;
	while (y < g_max)
	{
		x = 0;
		while (x < g_max)
		{
			map[g_row + y][g_col + x] = p_info->full;
			x++;
		}
		y++;
	}
	put_map(map, p_info);
}

void	generate_answer(char **map, t_info *p_info)
{
	t_coord	*p_coord;

	g_max = 0;
	g_col = 0;
	g_row = 0;
	p_coord = malloc(sizeof(t_coord));
	if (!p_coord)
		exit(EXIT_FAILURE);
	p_coord->y = 0;
	while (p_coord->y < p_info->map_height)
	{
		p_coord->x = 0;
		while (p_coord->x < p_info->map_width)
		{
			if (is_empty_spot_on_map(map, p_coord->x, p_coord->y, p_info))
			{
				check_for_square(map, p_coord, p_info);
			}
			p_coord->x++;
		}
		p_coord->y++;
	}
	ft_change_map(map, p_info);
	free(p_coord);
}
