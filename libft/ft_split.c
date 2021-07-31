/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:31:21 by thi-nguy          #+#    #+#             */
/*   Updated: 2021/07/28 14:36:41 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	hasword;

	i = 0;
	words = 0;
	hasword = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			hasword = 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				words++;
		}
		else
			i++;
	}
	return (words + hasword);
}

static	char	*ft_alloc_word(char const *s, char c)
{
	int		size;
	char	*tab;

	size = 0;
	tab = 0;
	while (s[size] && s[size] != c)
		size++;
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s, size + 1);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		words;
	char	**tab;

	count = -1;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (++count < words)
	{
		while (s[0] == c)
			s++;
		tab[count] = ft_alloc_word(s, c);
		if (!tab[count])
		{
			free_array(&tab);
			return (NULL);
		}
		s += ft_strlen(tab[count]);
	}
	tab[count] = 0;
	return (tab);
}
