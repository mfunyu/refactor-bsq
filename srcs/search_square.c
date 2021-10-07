/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:09:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	_is_square_placable(const char **map, t_coord *p_coord,
							int sq_size, t_info *p_info)
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

void	search_square(const char **map, t_coord *p_coord, t_info *p_info)
{
	int	sq_size;

	sq_size = 0;
	while (_is_square_placable(map, p_coord, sq_size, p_info))
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
