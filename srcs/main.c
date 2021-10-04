/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 15:35:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_map(char ***map)
{
	long int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

int	get_len_first_line(char *content)
{
	int		len;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	return (len);
}

int	check_input_and_generate_map(char *content)
{
	char	**map;
	t_info	info;
	int		first_line_len;

	if (check_newline_at_eof(content) == FAIL)
		return (FAIL);
	first_line_len = get_len_first_line(content);
	if (first_line_len < 4)
		return (FAIL);
	if (check_first_line(content, first_line_len) == FAIL)
		return (FAIL);
	if (parse_first_line(&info, content, first_line_len) == FAIL)
		return (FAIL);
	map = ft_split(content + first_line_len, "\n");
	if (!map)
		return (FAIL);
	free(content);
	if (check_map_structure(map, &info) == FAIL)
		return (FAIL);
	generate_correct_map(map, &info);
	free_map(&map);
	return (SUCCESS);
}

int	map_from_stdin(void)
{
	char	*content;

	content = read_from_fd(STDIN_FILENO);
	if (!content)
		return (FAIL);
	if (check_input_and_generate_map(content) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	map_from_file(char *filename)
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
		if (map_from_stdin() == FAIL)
			ft_puterror(FT_ERR_MAP);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (map_from_file(argv[i]) == FAIL)
			ft_puterror(FT_ERR_MAP);
		i++;
		if (i != argc)
			ft_putstr("\n");
	}
	return (0);
}
