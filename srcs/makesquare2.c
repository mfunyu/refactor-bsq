/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 23:11:47 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_max;
int		g_col;
int		g_row;

int	is_square_placable(char **map, t_tempcrs *p_tempcrs, int sq_size, t_info *p_info)
{
	int	i;

	i = 0;
	while (i <= sq_size)
	{
		if (!is_empty_spot_on_map(map, p_tempcrs->x + i,
				p_tempcrs->y + sq_size, p_info))
			return (0);
		i++;
	}
	i = 0;
	while (i <= sq_size)
	{
		if (!is_empty_spot_on_map(map, p_tempcrs->x + sq_size,
				p_tempcrs->y + i, p_info))
			return (0);
		i++;
	}
	return (1);
}

void	check_for_square(char **map, t_tempcrs *p_tempcrs, t_info *p_info)
{
	int	sq_size;

	sq_size = 0;
	while (is_square_placable(map, p_tempcrs, sq_size, p_info))
	{
		sq_size++;
	}
	if (g_max < sq_size)
	{
		g_max = sq_size;
		g_col = p_tempcrs->x;
		g_row = p_tempcrs->y;
	}
}

void	ft_change_map(char **map, t_info *p_info)
{
	int		x;
	int		y;

	y = 0;
	while (y < g_max)
	{
		x = 0;
		while (x < g_max)
		{
			map[g_row + y][g_col + x] = p_info->full;
			x++;
		}
		y++;
	}
	put_map(map, p_info);
}

void	generate_answer(char **map, t_info *p_info)
{
	t_tempcrs	*p_tempcrs;

	g_max = 0;
	g_col = 0;
	g_row = 0;
	p_tempcrs = malloc(sizeof(t_tempcrs));
	if (!p_tempcrs)
		exit(EXIT_FAILURE);
	set_tempcrs(p_tempcrs);
	while (p_tempcrs->y < p_info->map_height)
	{
		p_tempcrs->x = 0;
		while (p_tempcrs->x < p_info->map_width)
		{
			if (is_empty_spot_on_map(map, p_tempcrs->x, p_tempcrs->y, p_info))
			{
				check_for_square(map, p_tempcrs, p_info);
			}
			p_tempcrs->x++;
		}
		p_tempcrs->y++;
	}
	ft_change_map(map, p_info);
	free(p_tempcrs);
}
