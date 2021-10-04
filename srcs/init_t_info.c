/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/04 23:27:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	init_t_info(t_info *info, char **map, char *content, int len)
{
	int		i;
	char	*num;
	int		row_size_digits;

	row_size_digits = len - 3;
	num = malloc(sizeof(char) * (row_size_digits + 1));
	if (!num)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < row_size_digits)
		num[i] = content[i];
	num[i] = '\0';
	info->map_height = ft_atoi(num);
	info->map_width = ft_strlen(map[0]);
	info->empty = content[row_size_digits];
	info->obstacle = content[row_size_digits + 1];
	info->full = content[row_size_digits + 2];
	info->max_sq_size = 0;
	info->sq_x_coord = 0;
	info->sq_y_coord = 0;
	free(num);
	return (SUCCESS);
}
