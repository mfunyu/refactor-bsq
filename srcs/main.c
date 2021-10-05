/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 16:13:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	load_map_from_stdin(void)
{
	char	*content;

	content = read_from_fd(STDIN_FILENO);
	if (!content)
		return (FAIL);
	if (check_input_and_generate_map(content) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	load_map_from_file(char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	content = read_from_fd(fd);
	close(fd);
	if (!content)
		return (FAIL);
	if (check_input_and_generate_map(content) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 1)
	{
		if (load_map_from_stdin() == FAIL)
			ft_puterror(FT_ERR_MAP);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (load_map_from_file(argv[i]) == FAIL)
			ft_puterror(FT_ERR_MAP);
		i++;
		if (i != argc)
			ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}
