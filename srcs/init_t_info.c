/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/05 15:05:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	init_t_info(t_info *info, char **map, char *content, int len)
{
	int		row_size_digits;

	info->map_height = ft_atoi(content);
	info->map_width = ft_strlen(map[0]);
	row_size_digits = len - 3;
	info->empty = content[row_size_digits];
	info->obstacle = content[row_size_digits + 1];
	info->full = content[row_size_digits + 2];
	info->max_sq_size = 0;
	info->sq_x_coord = 0;
	info->sq_y_coord = 0;
	return (SUCCESS);
}
