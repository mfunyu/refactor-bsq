/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 02:41:14 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_word_index = 0;
int		g_start = 0;
int		g_end = 0;
int		g_state = 0;

int	is_in_charset(char c, char *charset)
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

int	get_wc(char *str, char *charset)
{
	int	wc;
	int	inside_word;

	wc = 0;
	inside_word = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset))
			inside_word = 0;
		else if (!inside_word)
		{
			inside_word = 1;
			++wc;
		}
		++str;
	}
	return (wc);
}

void	set_one_word(char **word_lst, char *str, int start, int end)
{
	int		i;

	i = 0;
	while (start <= end)
	{
		word_lst[g_word_index][i] = str[start];
		start++;
		i++;
	}
	word_lst[g_word_index][i] = '\0';
}

int	add_last_word(char **word_lst, char *str, int i)
{
	if (g_state == IN)
	{
		word_lst[g_word_index] = malloc(sizeof(char) * ((i - g_start) + 1));
		if (!word_lst[g_word_index])
			return (FAIL);
		set_one_word(word_lst, str, g_start, i);
		g_word_index++;
	}
	word_lst[g_word_index] = 0;
	g_word_index = 0;
	g_start = 0;
	g_end = 0;
	g_state = 0;
	return (SUCCESS);
}

char	**ft_split(char *str, char *charset)
{
	char	**word_lst;
	int		i;

	word_lst = malloc(sizeof(char *) * (get_wc(str, charset) + 1));
	if (!word_lst)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (is_in_charset(str[i], charset))
		{
			if (g_state == OUT)
				continue ;
			g_state = OUT;
			word_lst[g_word_index] = malloc(sizeof(char) * ((g_end - g_start) + 1));
			if (!word_lst[g_word_index])
				return (NULL);
			set_one_word(word_lst, str, g_start, g_end);
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
	if (add_last_word(word_lst, str, i) == FAIL)
		return (NULL);
	return (word_lst);
}
