/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:50:56 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utils.h"

static int	_get_digits(int nb)
{
	int		digits;

	digits = 1;
	while (nb / 10)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

static bool	_is_valid_map_height(const char *content, t_info *info)
{
	int		i;
	int		digits;

	info->map_height = ft_atoi(content);
	if (info->map_height <= 0)
		return (false);
	digits = _get_digits(info->map_height);
	i = 0;
	while ('0' <= content[i] && content[i] <= '9')
		i++;
	if (i != digits)
		return (false);
	return (true);
}

static bool	_is_valid_char_defined(const char *content, t_info *info)
{
	int		i;

	i = 0;
	while ('0' <= content[i] && content[i] <= '9')
		i++;
	info->empty = content[i];
	info->obstacle = content[i + 1];
	info->full = content[i + 2];
	if (!ft_is_printable(info->empty)
		|| !ft_is_printable(info->obstacle)
		|| !ft_is_printable(info->full))
		return (false);
	if (info->empty == info->obstacle
		|| info->obstacle == info->full
		|| info->full == info->empty)
		return (false);
	return (true);
}

bool	is_valid_input(const char *content, t_info *info)
{
	if (content[ft_strlen(content) - 1] != '\n')
		return (false);
	if (!_is_valid_map_height(content, info))
		return (false);
	if (!_is_valid_char_defined(content, info))
		return (false);
	return (true);
}
