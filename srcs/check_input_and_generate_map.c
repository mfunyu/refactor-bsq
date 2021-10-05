/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_and_generate_map.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 16:11:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	_get_len_first_line(char *content)
{
	int		len;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	return (len);
}

int	check_input_and_generate_map(char *content)
{
	char	**map;
	t_info	info;
	int		first_line_len;

	if (content[ft_strlen(content) - 1] != '\n')
		return (FAIL);
	first_line_len = _get_len_first_line(content);
	if (check_first_line(content, first_line_len) == FAIL)
		return (FAIL);
	map = ft_split(content + first_line_len, "\n");
	if (!map)
		exit(EXIT_FAILURE);
	if (!map[0])
		return (FAIL);
	if (init_t_info(&info, map, content, first_line_len) == FAIL)
		return (FAIL);
	free(content);
	if (check_map_structure(map, &info) == FAIL)
		return (FAIL);
	generate_answer(map, &info);
	free_map(&map);
	return (SUCCESS);
}
