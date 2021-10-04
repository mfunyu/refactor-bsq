/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 16:42:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_max;
int		g_col;
int		g_row;

int	ft_check_2(char **map, t_tempcrs *p_tempcrs, t_info *p_info)
{
	int	i;

	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_check_1(map, p_tempcrs->x + i,
				p_tempcrs->y + p_tempcrs->size, p_info) == 0)
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_check_1(map, p_tempcrs->x + p_tempcrs->size,
				p_tempcrs->y + i, p_info) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_3(char **map, t_tempcrs *p_tempcrs, t_info *p_info)
{
	p_tempcrs->size = 0;
	while (ft_check_2(map, p_tempcrs, p_info) == 1)
	{
		p_tempcrs->size++;
	}
	if (g_max < p_tempcrs->size)
	{
		g_max = p_tempcrs->size;
		g_col = p_tempcrs->x;
		g_row = p_tempcrs->y;
	}
}

void	ft_put_map(char **map, t_info *p_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_info->map_height)
	{
		x = 0;
		while (x < p_info->map_width)
		{
			ft_putchar_fd(map[y][x], STDOUT_FILENO);
			x++;
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		y++;
	}
}

void	ft_change_map(char **map, t_info *p_info)
{
	int		x;
	int		y;
	t_bsq	*p_bsq;

	y = 0;
	p_bsq = malloc(sizeof(t_bsq));
	set_bsq(p_bsq);
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
	ft_put_map(map, p_info);
	free(p_bsq);
	return ;
}

void	generate_correct_map(char **map, t_info *p_info)
{
	t_tempcrs	*p_tempcrs;

	g_max = 0;
	g_col = 0;
	g_row = 0;
	p_tempcrs = malloc(sizeof(t_tempcrs));
	set_tempcrs(p_tempcrs);
	while (p_tempcrs->y < p_info->map_height)
	{
		p_tempcrs->x = 0;
		while (p_tempcrs->x < p_info->map_width)
		{
			if (ft_check_1(map, p_tempcrs->x,
					p_tempcrs->y, p_info) == 1)
			{
				ft_check_3(map, p_tempcrs, p_info);
			}
			p_tempcrs->x++;
		}
		p_tempcrs->y++;
	}
	ft_change_map(map, p_info);
	free(p_tempcrs);
	return ;
}
