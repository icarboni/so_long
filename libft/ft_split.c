/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:10:32 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/30 13:55:08 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free(char **res, int w)
{
	while (w >= 0)
	{
		free(res[w]);
		res[w] = NULL;
		w--;
	}
	free(res);
	res = 0;
	return (0);
}

static int	ft_words_count(char const *s, char c)
{
	int	words;
	int	end;

	words = 0;
	end = 0;
	while (*s)
	{
		if (*s != c && end == 0)
		{
			end = 1;
			words++;
		}
		else if (*s == c)
			end = 0;
		s++;
	}
	return (words + 1);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (word != NULL)
	{
		while (start < finish)
			word[i++] = str[start++];
		word[i] = '\0';
		return (word);
	}
	else
		return (NULL);
}

int	ft_exe(char const *s, char c, char **res)
{
	int		i;
	int		w;
	int		index;

	i = 0;
	w = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c | i == ft_strlen(s)) && index >= 0)
		{
			res[w] = word_dup(s, index, i);
			if (res[w++] == NULL)
				return (ft_free(res, --w));
			index = -1;
		}
		i++;
	}
	res[w] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = malloc(ft_words_count(s, c) * sizeof(char *));
	if (!s || !res)
		return (0);
	if (ft_exe(s, c, res) == 0)
		return (NULL);
	return (res);
}
