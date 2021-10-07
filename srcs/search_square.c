/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 01:57:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "validate.h"

static bool	_is_square_placable(const char **map, t_coord *p_coord,
							int sq_size, t_info *p_info)
{
	int	i;

	i = 0;
	while (i <= sq_size)
	{
		if (!is_valid_coordinate(map, p_coord->x + i,
				p_coord->y + sq_size, p_info))
			return (false);
		i++;
	}
	i = 0;
	while (i <= sq_size)
	{
		if (!is_valid_coordinate(map, p_coord->x + sq_size,
				p_coord->y + i, p_info))
			return (false);
		i++;
	}
	return (true);
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
