/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 15:31:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
	if (p_info->max_sq_size < sq_size)
	{
		p_info->max_sq_size = sq_size;
		p_info->sq_x_coord = p_coord->x;
		p_info->sq_y_coord = p_coord->y;
	}
}

void	place_square_on_map(char **map, t_info *p_info)
{
	int		x;
	int		y;

	y = 0;
	while (y < p_info->max_sq_size)
	{
		x = 0;
		while (x < p_info->max_sq_size)
		{
			map[p_info->sq_y_coord + y][p_info->sq_x_coord + x] = p_info->full;
			x++;
		}
		y++;
	}
}

void	generate_answer(char **map, t_info *p_info)
{
	t_coord	p_coord;

	p_coord.y = 0;
	while (p_coord.y < p_info->map_height)
	{
		p_coord.x = 0;
		while (p_coord.x < p_info->map_width)
		{
			if (is_empty_spot_on_map(map, p_coord.x, p_coord.y, p_info))
			{
				check_for_square(map, &p_coord, p_info);
			}
			p_coord.x++;
		}
		p_coord.y++;
	}
	place_square_on_map(map, p_info);
	put_map(map, p_info);
}
