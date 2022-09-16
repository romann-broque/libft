/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:29:49 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/16 14:11:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	bool	is_word;

	count = 0;
	is_word = false;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (is_word == true)
			{
				++count;
				is_word = false;
			}
		}
		else
			is_word = true;
		++s;
	}
	return (count + (is_word == true));
}

static size_t	get_wordlen(const char *s, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen] != '\0' && s[wordlen] != c)
		++wordlen;
	return (wordlen);
}

static char	*get_word(const char **s, char c)
{
	const size_t	wordlen = get_wordlen(*s, c);
	char			*word;

	while (**s == c)
		++(*s);
	word = ft_strndup(*s, wordlen);
	*s += wordlen;
	return (word);
}

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}


char	**ft_split(char const *s, char c)
{
	size_t	nbof_words;
	size_t	i;
	char	**split;

	if (s == NULL)
		return (NULL);
	nbof_words = count_words(s, c);
	split = (char **)malloc((nbof_words + 1) * sizeof(char *));
	if (split != NULL)
	{
		i = 0;
		split[nbof_words] = NULL;
		while (i < nbof_words)
		{
			split[i] = get_word(&s, c);
			if (split[i] == NULL)
			{
				free_strs(split);
				split = NULL;
				break ;
			}
			++i;
		}
	}
	return (split);
}
