/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:51:16 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utils.h"

static char	*_read_from_fd(const int fd)
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
		if (!content)
			exit(EXIT_FAILURE);
	}
	return (content);
}

int	read_map_from_stdin(char **content)
{
	*content = _read_from_fd(STDIN_FILENO);
	if (!(*content))
		return (FAIL);
	return (SUCCESS);
}

int	read_map_from_file(const char *filename, char **content)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	*content = _read_from_fd(fd);
	close(fd);
	if (!(*content))
		return (FAIL);
	return (SUCCESS);
}
