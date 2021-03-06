/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 01:39:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	_free_map(char ***p_map)
{
	long int	i;
	char		**map;

	map = *p_map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_map_and_content(char ***p_map, char *content)
{
	if (p_map)
		_free_map(p_map);
	free(content);
}

int	free_return_fail(char ***p_map, char *content)
{
	free_map_and_content(p_map, content);
	return (FAIL);
}
