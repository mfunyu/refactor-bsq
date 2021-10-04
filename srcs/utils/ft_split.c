/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 02:19:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_word_index = 0;
int		g_start = 0;
int		g_end = 0;
int		g_state = 0;

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_wc(char *str, char *charset)
{
	int	wc;
	int	state;

	wc = 0;
	state = OUT;
	while (*str)
	{
		if (ft_is_in_charset(*str, charset))
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
		++str;
	}
	return (wc);
}

int	ft_add_last_word(char **res, char *str, int i)
{
	int	j;

	if (g_state == IN)
	{
		res[g_word_index] = malloc(sizeof(char) * ((i - g_start) + 1));
		if (!res[g_word_index])
			return (FAIL);
		j = -1;
		while (g_start <= i)
			res[g_word_index][++j] = str[g_start++];
		res[g_word_index][++j] = '\0';
		g_word_index++;
	}
	res[g_word_index] = 0;
	g_word_index = 0;
	g_start = 0;
	g_end = 0;
	g_state = 0;
	return (SUCCESS);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (ft_get_wc(str, charset) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (ft_is_in_charset(str[i], charset))
		{
			if (g_state == OUT)
				continue ;
			g_state = OUT;
			res[g_word_index] = malloc(sizeof(char) * ((g_end - g_start) + 1));
			if (!res[g_word_index])
				return (NULL);
			j = -1;
			while (g_start <= g_end)
				res[g_word_index][++j] = str[g_start++];
			res[g_word_index][++j] = '\0';
			g_word_index++;
		}
		else
		{
			if (g_state == OUT)
			{
				g_state = IN;
				g_start = i;
				g_end = i;
			}
			else
				g_end = i;
		}
	}
	if (ft_add_last_word(res, str, i) == FAIL)
		return (NULL);
	return (res);
}
