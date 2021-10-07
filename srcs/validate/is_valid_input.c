/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 01:07:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "validate.h"
#include "utils.h"

bool	is_valid_input(const char *content, t_info *info)
{
	if (content[ft_strlen(content) - 1] != '\n')
		return (false);
	if (!is_valid_chars(content, info))
		return (false);
	if (!is_valid_map_height(content, info))
		return (false);
	return (true);
}
