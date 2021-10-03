/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 01:04:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_map_first_line(char *content, int len)
{
	int		i;
	int		empty;
	int		obstacle;
	int		full;

	i = -1;
	while (++i < len - 3)
		if (content[i] < '0' || content[i] > '9')
			return (FAIL);
	empty = i;
	obstacle = i + 1;
	full = i + 2;
	if (!ft_is_printable(content[empty])
		|| !ft_is_printable(content[obstacle])
		|| !ft_is_printable(content[full]))
		return (FAIL);
	if (content[empty] == content[obstacle]
		|| content[obstacle] == content[full]
		|| content[full] == content[empty])
		return (FAIL);
	return (SUCCESS);
}

t_info	*parse_first_line(char *content, int len)
{
	t_info	*info;
	int		i;
	char	*num;
	int		row_size_digits;

	row_size_digits = len - 3;
	info = malloc(sizeof(t_info *));
	num = malloc(sizeof(char) * (row_size_digits + 1));
	i = -1;
	while (++i < row_size_digits)
		num[i] = content[i];
	num[i] = '\0';
	info->num_rows = ft_atoi(num);
	info->empty = content[row_size_digits];
	info->obstacle = content[row_size_digits + 1];
	info->full = content[row_size_digits + 2];
	free(num);
	return (info);
}
