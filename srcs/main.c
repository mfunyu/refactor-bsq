/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/04 00:26:48 by mfunyu           ###   ########.fr       */
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

char	*read_from_fd(int fd)
{
	char	*content;
	char	*tmp;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	content = NULL;
	while (1)
	{
		n = read(fd, buf, FT_BUFSIZ);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(content, buf);
			free(content);
			content = tmp;
		}
	}
	return (content);
}

int	map_from_stdin(void)
{
	char	*content;
	char	**map;
	t_info	*info;

	content = read_from_fd(STDIN_FILENO);
	if (!content)
		return (FAIL);
	if (check_newline_at_eof(content) == FAIL)
		return (FAIL);
	map = ft_split(content, "\n");
	if (!map)
		return (FAIL);
	free(content);
	if (check_map_first_line(map[0]) == FAIL)
		return (FAIL);
	info = parse_first_line(map[0]);
	if (!info)
		return (FAIL);
	if (check_map_structure(map, info) == FAIL)
		return (FAIL);
	generate_correct_map(map, info);
	free_map(&map);
	free(info);
	return (SUCCESS);
}

int	map_from_file(char *filename)
{
	int		fd;
	char	*content;
	char	**map;
	t_info	*info;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	content = read_from_fd(fd);
	close(fd);
	if (!content)
		return (FAIL);
	if (check_newline_at_eof(content) == FAIL)
		return (FAIL);
	map = ft_split(content, "\n");
	free(content);
	if (check_map_first_line(map[0]) == FAIL)
		return (FAIL);
	info = parse_first_line(map[0]);
	if (!info)
		return (FAIL);
	if (check_map_structure(map, info) == FAIL)
		return (FAIL);
	generate_correct_map(map, info);
	free_map(&map);
	free(info);
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
