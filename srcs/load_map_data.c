/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 00:49:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utils.h"

static const char	*_skip_header(const char *content)
{
	while (*content != '\n')
		content++;
	return (content);
}

int	load_map_data(char ***p_map, const char *content, t_info *info)
{
	char	**map;

	*p_map = ft_split(_skip_header(content), "\n");
	map = *p_map;
	if (!map)
		exit(EXIT_FAILURE);
	if (!map[0])
		return (FAIL);
	info->map_width = ft_strlen(map[0]);
	info->max_sq_size = 0;
	info->sq_x_coord = 0;
	info->sq_y_coord = 0;
	return (SUCCESS);
}
