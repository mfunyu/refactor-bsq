/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:49:05 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/07 16:54:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

/*
** utils
*/
int		ft_atoi(const char *str);
int		ft_is_printable(const char c);

void	ft_putchar_fd(const char c, const int fd);
void	ft_putstr_fd(const char *str, const int fd);
void	ft_puterror(const char *str);

char	**ft_split(const char *str, const char *charset);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *str);

#endif
