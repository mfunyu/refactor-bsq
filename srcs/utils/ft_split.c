/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:46:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	_is_in_charset(char c, const char *charset)
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

static int	_get_words_count(const char *str, const char *charset)
{
	int	words_count;
	int	inside_word;

	words_count = 0;
	inside_word = 0;
	while (*str)
	{
		if (_is_in_charset(*str, charset))
			inside_word = 0;
		else if (!inside_word)
		{
			inside_word = 1;
			words_count++;
		}
		str++;
	}
	return (words_count);
}

static int	_set_one_word(char **words_lst, const char *str, int start, int end)
{
	char	*word_to_set;
	int		i;

	i = 0;
	*words_lst = malloc(sizeof(char) * ((end - start) + 1));
	word_to_set = *words_lst;
	if (!word_to_set)
		return (FAIL);
	while (start <= end)
	{
		word_to_set[i] = str[start];
		start++;
		i++;
	}
	word_to_set[i] = '\0';
	return (SUCCESS);
}

static int	_loop_check_str(char **words_lst,
								const char *str, const char *charset)
{
	int		inside_word;
	int		word_head;
	int		i;

	i = -1;
	inside_word = 0;
	while (str[++i])
	{
		if (_is_in_charset(str[i], charset))
		{
			if (!inside_word)
				continue ;
			inside_word = 0;
			if (_set_one_word(words_lst++, str, word_head, i - 1) == FAIL)
				return (FAIL);
		}
		else if (!inside_word)
		{
			inside_word = 1;
			word_head = i;
		}
	}
	if (inside_word && _set_one_word(words_lst, str, word_head, i) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

char	**ft_split(const char *str, const char *charset)
{
	char	**words_lst;
	int		words_count;

	words_count = _get_words_count(str, charset);
	words_lst = malloc(sizeof(char *) * (words_count + 1));
	if (!words_lst)
		return (NULL);
	if (_loop_check_str(words_lst, str, charset) == FAIL)
		return (NULL);
	words_lst[words_count] = NULL;
	return (words_lst);
}
