/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 16:15:39 by mfunyu           ###   ########.fr       */
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
		if (ft_check_1(map, p_tempcrs->col + i,
				p_tempcrs->row + p_tempcrs->size, p_info) == 0)
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_check_1(map, p_tempcrs->col + p_tempcrs->size,
				p_tempcrs->row + i, p_info) == 0)
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
		g_col = p_tempcrs->col;
		g_row = p_tempcrs->row;
	}
}

void	ft_put_map(char **map, t_info *p_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < p_info->map_height)
	{
		j = 0;
		while (j < p_info->map_width)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_change_map(char **map, t_info *p_info)
{
	int		i;
	int		j;
	t_bsq	*p_bsq;

	i = 0;
	p_bsq = malloc(sizeof(t_bsq));
	set_bsq(p_bsq);
	while (i < g_max)
	{
		j = 0;
		while (j < g_max)
		{
			map[g_row + i][g_col + j] = p_info->full;
			j++;
		}
		i++;
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
	while (p_tempcrs->row < p_info->map_height)
	{
		p_tempcrs->col = 0;
		while (p_tempcrs->col < p_info->map_width)
		{
			if (ft_check_1(map, p_tempcrs->col,
					p_tempcrs->row, p_info) == 1)
			{
				ft_check_3(map, p_tempcrs, p_info);
			}
			p_tempcrs->col++;
		}
		p_tempcrs->row++;
	}
	ft_change_map(map, p_info);
	free(p_tempcrs);
	return ;
}
