/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 21:23:52 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_map_chars(char **map, t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != info->empty && map[y][x] != info->obstacle)
				return (FAIL);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	check_map_shape_size(char **map, t_info *info)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != info->map_width)
			return (FAIL);
		y++;
	}
	if (y != info->map_height)
		return (FAIL);
	return (SUCCESS);
}

int	check_newline_at_eof(char *content)
{
	int		i;

	i = 0;
	while (content[i] != '\0')
		i++;
	if (content[i - 1] != '\n')
		return (FAIL);
	return (SUCCESS);
}

int	check_map_structure(char **map, t_info *info)
{
	if (check_map_chars(map, info) == FAIL)
		return (FAIL);
	if (check_map_shape_size(map, info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}