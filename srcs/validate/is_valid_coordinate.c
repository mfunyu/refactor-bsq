/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "validate.h"

static bool	_is_empty(const char **map, int x, int y, t_info *info)
{
	return (map[y][x] == info->empty);
}

static bool	_is_inside_map(int x, int y, t_info *info)
{
	return (x < info->map_width && y < info->map_height);
}

bool	is_valid_coordinate(const char **map, int x, int y, t_info *info)
{
	return (_is_inside_map(x, y, info) && _is_empty(map, x, y, info));
}
