/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/03 17:34:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_map_chars(char **map, t_info *info)
{
	int	x;
	int	y;

	y = 1;
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

	i = 1;
	len = ft_strlen(map[1]);
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (FAIL);
		i++;
	}
	if (i - 1 != info->num_rows)
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
	if (!map[1])
		return (FAIL);
	if (check_map_chars(map, info) == FAIL)
		return (FAIL);
	if (check_len_rows_cols(map, info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
