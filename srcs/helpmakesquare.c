/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmakesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 16:34:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	set_tempcrs(t_tempcrs *p_tempcrs)
{
	p_tempcrs->y = 0;
	p_tempcrs->x = 0;
	p_tempcrs->size = 0;
}

int	ft_check_1(char **map, int x, int y, t_info *p_info)
{
	if (x == p_info->map_width)
	{
		return (0);
	}
	if (y == p_info->map_height)
	{
		return (0);
	}
	if (map[y][x] == p_info->obstacle || map[y][x] == '\0')
	{
		return (0);
	}
	return (1);
}

void	set_bsq(t_bsq *p_bsq)
{
	p_bsq->x = g_col;
	p_bsq->y = g_row;
	p_bsq->size = g_max;
}
