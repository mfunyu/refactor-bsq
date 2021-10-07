/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 16:11:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static bool	_is_valid_map_chars(const char **map, t_info *info)
{
	int	x;
	int	y;
	int	no_empty_spot;

	y = 0;
	no_empty_spot = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != info->empty && map[y][x] != info->obstacle)
				return (false);
			if (map[y][x] == info->empty)
				no_empty_spot = 0;
			x++;
		}
		y++;
	}
	if (no_empty_spot)
		return (false);
	return (true);
}

static bool	_is_valid_map_shape_size(const char **map, t_info *info)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != info->map_width)
			return (false);
		y++;
	}
	if (y != info->map_height)
		return (false);
	return (true);
}

bool	is_valid_map_structure(const char **map, t_info *info)
{
	if (!_is_valid_map_chars(map, info))
		return (false);
	if (!_is_valid_map_shape_size(map, info))
		return (false);
	return (true);
}
