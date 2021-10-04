/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 16:06:56 by mfunyu           ###   ########.fr       */
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

int	check_len_rows_cols(char **map, t_info *info)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (FAIL);
		i++;
	}
	if (i != info->map_height)
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
	if (!map[0])
		return (FAIL);
	if (check_map_chars(map, info) == FAIL)
		return (FAIL);
	if (check_len_rows_cols(map, info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
