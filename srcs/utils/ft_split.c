/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 03:04:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int	set_one_word(char **word_lst, char *str, int start, int end)
{
	int		i;

	i = 0;
	*word_lst = malloc(sizeof(char) * ((end - start) + 1));
	if (!(*word_lst))
		return (FAIL);
	while (start <= end)
	{
		(*word_lst)[i] = str[start];
		start++;
		i++;
	}
	(*word_lst)[i] = '\0';
	return (SUCCESS);
}

char	**ft_split(char *str, char *charset)
{
	char	**word_lst;
	int		inside_word;
	int		word_head;
	int		word_index;
	int		i;

	word_lst = malloc(sizeof(char *) * (get_wc(str, charset) + 1));
	if (!word_lst)
		return (NULL);
	i = -1;
	inside_word = 0;
	word_index = 0;
	word_head = 0;
	while (str[++i])
	{
		if (is_in_charset(str[i], charset))
		{
			if (!inside_word)
				continue ;
			inside_word = 0;
			set_one_word(word_lst + word_index, str, word_head, i - 1);
			word_index++;
		}
		else
		{
			if (!inside_word)
			{
				inside_word = 1;
				word_head = i;
			}
		}
	}
	if (inside_word)
	{
		set_one_word(word_lst + word_index, str, word_head, i);
	}
	word_lst[word_index] = NULL;
	return (word_lst);
}
