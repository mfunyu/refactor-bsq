/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:46:13 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar_fd(const char c, const int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *str, const int fd)
{
	while (*str)
		ft_putchar_fd(*str++, fd);
}

void	ft_puterror(const char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
}
