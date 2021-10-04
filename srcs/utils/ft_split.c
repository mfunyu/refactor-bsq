/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 03:34:26 by mfunyu           ###   ########.fr       */
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

int	loop_check_str(char **word_lst, char *str, char *charset)
{
	int		inside_word;
	int		word_head;
	int		i;

	i = -1;
	inside_word = 0;
	while (str[++i])
	{
		if (is_in_charset(str[i], charset))
		{
			if (!inside_word)
				continue ;
			inside_word = 0;
			if (set_one_word(word_lst++, str, word_head, i - 1) == FAIL)
				return (FAIL);
		}
		else if (!inside_word)
		{
			inside_word = 1;
			word_head = i;
		}
	}
	if (inside_word && set_one_word(word_lst, str, word_head, i) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

char	**ft_split(char *str, char *charset)
{
	char	**word_lst;
	int		words_count;

	words_count = get_wc(str, charset);
	word_lst = malloc(sizeof(char *) * (words_count + 1));
	if (!word_lst)
		return (NULL);
	if (loop_check_str(word_lst, str, charset) == FAIL)
		return (NULL);
	word_lst[words_count] = NULL;
	return (word_lst);
}
