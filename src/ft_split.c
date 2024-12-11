/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:10:16 by iportill          #+#    #+#             */
/*   Updated: 2024/02/15 18:10:17 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_wordlen(char *s, char c)
{
	int	i ;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_count_words(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		len++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (len);
}

char	*ft_word_dupe(char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*dupe;

	if (s == NULL)
		return (NULL);
	len = ft_wordlen(s, c);
	dupe = ft_calloc(sizeof(char), len + 1);
	if (dupe == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

int	ft_fill_words(char **array, char *s, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (s == NULL)
		return (1);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		array[index] = ft_word_dupe(s + i, c);
		index++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	int		num_words;
	char	**array;
	int		i;

	array = NULL;
	num_words = ft_count_words(s, c);
	array = ft_calloc(sizeof(char *), num_words + 1);
	i = 0;
	if (ft_fill_words(array, s, c) == 1)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	array[num_words] = NULL;
	return (array);
}
