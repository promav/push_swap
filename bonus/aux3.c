/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:27:39 by pabromer          #+#    #+#             */
/*   Updated: 2024/09/24 11:05:05 by pabromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

unsigned int	mallocsize(char const *s, char c)
{
	int	ms;
	int	i;

	i = 0;
	ms = 0;
	if (s[0] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			ms++;
		i++;
	}
	if (s[i - 1] != c)
		ms++;
	return (ms);
}

void	*freessplit(char **ssplit, int k)
{
	while (k >= 0)
	{
		free(ssplit[k]);
		k--;
	}
	free(ssplit);
	return (NULL);
}

char	**fillsplit(char **ssplit, char const *s, char c)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	k = 0;
	j = -1;
	while (i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && j == -1)
			j = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && j != -1)
		{
			ssplit[k] = ft_substr(s, j, i - j);
			if (!ssplit[k])
				if (freessplit(ssplit, k) == NULL)
					return (NULL);
			k++;
			j = -1;
		}
		i++;
	}
	ssplit[k] = NULL;
	return (ssplit);
}

char	**ft_split(char const *s, char c)
{
	char	**ssplit;

	ssplit = (char **)malloc((mallocsize(s, c) + 1) * sizeof(char *));
	if (!ssplit)
		return (NULL);
	ssplit = fillsplit(ssplit, s, c);
	if (!ssplit)
		return (freessplit(ssplit, mallocsize(s, c)));
	return (ssplit);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	subs = (char *) malloc(len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
