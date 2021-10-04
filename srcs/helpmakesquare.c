/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmakesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 15:23:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_map_colsize(char **map)
{
	int	count;

	count = 0;
	while (map[0][count])
	{
		count++;
	}
	return (count);
}

void	set_tempcrs(t_tempcrs *p_tempcrs)
{
	p_tempcrs->row = 0;
	p_tempcrs->col = 0;
	p_tempcrs->size = 0;
}

int	ft_check_1(char **map, int col, int row, t_info *p_info)
{
	if (col == ft_map_colsize(map))
	{
		return (0);
	}
	if (row == p_info->num_rows)
	{
		return (0);
	}
	if (map[row][col] == p_info->obstacle || map[row][col] == '\0')
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
