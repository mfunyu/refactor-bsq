/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_height.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:53:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/08 00:57:03 by mfunyu           ###   ########.fr       */
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

static char	*_get_header(const char *content)
{
	char	*header;
	int		map_height_tail;

	map_height_tail = header_len(content) - NUM_MAPCHARS;
	header = ft_strdup(content);
	header[map_height_tail] = '\0';
	return (header);
}

bool	is_valid_map_height(const char *content, t_info *info)
{
	int		i;
	int		digits;
	char	*header;

	header = _get_header(content);
	info->map_height = ft_atoi(header);
	if (info->map_height <= 0)
	{
		free(header);
		return (false);
	}
	digits = _get_digits(info->map_height);
	i = 0;
	while (header[i] && '0' <= header[i] && header[i] <= '9')
		i++;
	free(header);
	if (i != digits)
		return (false);
	return (true);
}
