/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 23:10:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_map_from_stdin(char **content)
{
	*content = read_from_fd(STDIN_FILENO);
	if (!(*content))
		return (FAIL);
	return (SUCCESS);
}

int	read_map_from_file(char *filename, char **content)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	*content = read_from_fd(fd);
	close(fd);
	if (!(*content))
		return (FAIL);
	return (SUCCESS);
}

void	bsq(char *filename)
{
	char	*content;
	t_info	info;
	char	**map;

	if (!filename)
	{
		if (read_map_from_stdin(&content) == FAIL)
			return (ft_puterror(FT_ERR_MAP));
	}
	else
	{
		if (read_map_from_file(filename, &content) == FAIL)
			return (ft_puterror(FT_ERR_MAP));
	}
	if (validate_input(content, &info) == FAIL)
		return (ft_puterror(FT_ERR_MAP));
	if (load_map_data(&map, content, &info) == FAIL)
		return (ft_puterror(FT_ERR_MAP));
	if (validate_map_structure(map, &info) == FAIL)
		return (ft_puterror(FT_ERR_MAP));
	generate_answer(map, &info);
	free_map(&map);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 1)
	{
		bsq(NULL);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		bsq(argv[i]);
		if (++i != argc)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}
