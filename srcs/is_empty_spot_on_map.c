/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_spot_on_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_empty_spot_on_map(const char **map, int x, int y, t_info *p_info)
{
	if (x == p_info->map_width)
		return (0);
	if (y == p_info->map_height)
		return (0);
	if (map[y][x] == p_info->obstacle || map[y][x] == '\0')
		return (0);
	return (1);
}
