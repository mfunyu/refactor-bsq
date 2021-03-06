/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/08 01:40:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "validate.h"
#include "utils.h"
#include "free.h"

int	bsq(const char *filename)
{
	char	*content;
	t_info	info;
	char	**map;

	if (!filename)
	{
		if (read_map_from_stdin(&content) == FAIL)
			return (FAIL);
	}
	else
	{
		if (read_map_from_file(filename, &content) == FAIL)
			return (FAIL);
	}
	if (!is_valid_input(content, &info))
		return (free_return_fail(NULL, content));
	if (load_map_data(&map, content, &info) == FAIL)
		return (free_return_fail(&map, content));
	if (!is_valid_map_structure((const char **) map, &info))
		return (free_return_fail(&map, content));
	solve((const char **) map, &info);
	apply_square_on_map(map, &info);
	put_map((const char **) map, &info);
	free_map_and_content(&map, content);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 1)
	{
		if (bsq(NULL) == FAIL)
			ft_puterror(FT_ERR_MAP);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (bsq(argv[i]) == FAIL)
			ft_puterror(FT_ERR_MAP);
		if (++i != argc)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}
