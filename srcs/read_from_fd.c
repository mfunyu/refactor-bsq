/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 16:17:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
		if (!content)
			exit(EXIT_FAILURE);
	}
	return (content);
}
