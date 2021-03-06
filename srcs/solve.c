/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:06:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "validate.h"

void	solve(const char **map, t_info *p_info)
{
	t_coord	p_coord;

	p_coord.y = 0;
	while (p_coord.y < p_info->map_height)
	{
		p_coord.x = 0;
		while (p_coord.x < p_info->map_width)
		{
			if (is_valid_coordinate(map, p_coord.x, p_coord.y, p_info))
				search_square(map, &p_coord, p_info);
			p_coord.x++;
		}
		p_coord.y++;
	}
}
