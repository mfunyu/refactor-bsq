/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:25:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/04 22:25:49 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	put_map(char **map, t_info *p_info)
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
