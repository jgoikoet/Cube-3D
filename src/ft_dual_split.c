/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dual_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:37 by iportill          #+#    #+#             */
/*   Updated: 2024/02/15 18:09:38 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_dual_wordlen(char *s, char c, char d)
{
	int	i ;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && (s[i] != c && s[i] != d))
		i++;
	return (i);
}

int	ft_dual_count_words(char *s, char c, char d)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (0);
	while (s[i] && (s[i] == c || s[i] == d))
		i++;
	while (s[i])
	{
		len++;
		while (s[i] && (s[i] != c && s[i] != d))
			i++;
		while (s[i] && (s[i] == c || s[i] == d))
			i++;
	}
	return (len);
}

char	*ft_dual_word_dupe(char *s, char c, char d)
{
	size_t	i;
	size_t	len;
	char	*dupe;

	if (s == NULL)
		return (NULL);
	len = ft_dual_wordlen(s, c, d);
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

int	ft_dual_fill_words(char **array, char *s, char c, char d)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (s == NULL)
		return (1);
	while (s[i] && (s[i] == c || s[i] == d))
		i++;
	while (s[i])
	{
		array[index] = ft_dual_word_dupe(s + i, c, d);
		index++;
		while (s[i] && (s[i] != c && s[i] != d))
			i++;
		while (s[i] && (s[i] == c || s[i] == d))
			i++;
	}
	return (0);
}

char	**ft_dual_split(char *s, char c, char d)
{
	int		num_words;
	char	**array;
	int		i;

	array = NULL;
	num_words = ft_dual_count_words(s, c, d);
	array = ft_calloc(sizeof(char *), (num_words +1));
	i = 0;
	if (ft_dual_fill_words(array, s, c, d) == 1)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	return (array);
}
