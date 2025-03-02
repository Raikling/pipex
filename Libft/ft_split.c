/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:21:07 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/11/10 09:14:14 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	find_next(const char *s, char c, size_t *start, size_t *end)
{
	while (s[*start] == c)
		(*start)++;
	*end = *start;
	while (s[*end] && s[*end] != c)
		(*end)++;
}

static int	split_words(const char *s, char c, char **split)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		find_next(s, c, &start, &end);
		split[i] = ft_substr(s, (unsigned int) start, (end - start));
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			return (0);
		}
		start = end;
		i++;
	}
	split[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!split_words(s, c, split))
	{
		free(split);
		return (NULL);
	}
	return (split);
}
