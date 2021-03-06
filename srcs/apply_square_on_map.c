/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_square_on_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	apply_square_on_map(char **map, const t_info *p_info)
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
