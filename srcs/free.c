/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(char ***map)
{
	long int	i;
	char		**p_map;

	p_map = *map;
	i = 0;
	while (p_map[i])
	{
		free(p_map[i]);
		i++;
	}
	free(p_map);
	p_map = NULL;
}
