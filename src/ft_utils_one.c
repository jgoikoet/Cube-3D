/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:10:20 by iportill          #+#    #+#             */
/*   Updated: 2024/02/15 18:10:21 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_arraylen(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

int	ft_count_array_len(char **arr)
{
	int	len;
	int	i;
	int	e;

	i = 0;
	e = 0;
	len = 0;
	if (arr == NULL)
		return (0);
	while (arr[i])
	{
		e = 0;
		while (arr[i][e])
		{
			e++;
			len++;
		}
		i++;
		len++;
	}
	return (len);
}

int	ft_atoi(const char *str)//
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num = (str[i] - 48) + (num * 10);
		i++;
	}
	return (num * sign);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*structure;

	structure = NULL;
	structure = malloc(num * size);
	if (structure == NULL)
		return (NULL);
	memset(structure, 0, num * size);
	return (structure);
}
