/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:10:23 by iportill          #+#    #+#             */
/*   Updated: 2024/12/11 13:43:06 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_calloc_for_ft_strjoin(const char	*s1, const char *s2)
{
	char	*result;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = NULL;
	result = ft_calloc(sizeof(char), len);
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		e;

	i = 0;
	result = ft_calloc_for_ft_strjoin(s1, s2);
	if (result == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	e = 0;
	while (s2 && s2[e])
	{
		result[i] = s2[e];
		i++;
		e++;
	}
	free((void *)s1);
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] != s2[i] && i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	dup = NULL;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s)+1;
	dup = ft_calloc(sizeof(char), len);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
