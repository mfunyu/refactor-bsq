/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 01:06:56 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

# include <stdbool.h>

# include "t_info.h"

typedef enum e_mapchars
{
	EMPTY,
	OBSTACLE,
	FULL,
	NUM_MAPCHARS
}			t_mapchars;

bool	is_valid_input(const char *content, t_info *info);
bool	is_valid_first_line(const char *content, t_info *info);
bool	is_valid_map_structure(const char **map, t_info *info);
bool	is_valid_chars(const char *content, t_info *info);
bool	is_valid_map_height(const char *content, t_info *info);
int		header_len(const char *content);

#endif
