/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:53:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/08 00:54:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utils.h"

static bool	_is_printable_chars(const t_info *info)
{
	return (ft_is_printable(info->empty)
		&& ft_is_printable(info->obstacle)
		&& ft_is_printable(info->full));
}

static bool	_is_unique_chars(const t_info *info)
{
	return (info->empty != info->obstacle
		&& info->obstacle != info->full
		&& info->full != info->empty);
}

bool	is_valid_chars(const char *content, t_info *info)
{
	int		chars_head;

	chars_head = header_len(content) - NUM_MAPCHARS;
	info->empty = content[chars_head + EMPTY];
	info->obstacle = content[chars_head + OBSTACLE];
	info->full = content[chars_head + FULL];
	if (!_is_printable_chars(info))
		return (false);
	if (!_is_unique_chars(info))
		return (false);
	return (true);
}
