/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:31 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 17:46:20 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_chars_in_playable_map(t_list *s)
{
	if (s->n == 1 && (s->s > 0 || s->e > 0 || s->w > 0))
		return (printf("Error\n11Initial position set multiple times\n"), 1);
	if (s->s == 1 && (s->n > 0 || s->e > 0 || s->w > 0))
		return (printf("Error\n22Initial position set multiple times\n"), 1);
	if (s->e == 1 && (s->s > 0 || s->n > 0 || s->w > 0))
		return (printf("Error\n33Initial position set multiple times\n"), 1);
	if (s->w == 1 && (s->s > 0 || s->e > 0 || s->n > 0))
		return (printf("Error\n44Initial position set multiple times\n"), 1);
	if (s->n != 0 && s->n != 1)
		return (printf("Error\nN set more than one time\n"), 1);
	if (s->s != 0 && s->s != 1)
		return (printf("Error\nS set more than one time\n"), 1);
	if (s->e != 0 && s->e != 1)
		return (printf("Error\nE set more than one time\n"), 1);
	if (s->w != 0 && s->w != 1)
		return (printf("Error\nW set more than one time\n"), 1);
	if (s->invalid_char != 0)
		return (printf("Error\nInvalid character in map\n"), 1);
	if (ft_check_initial_position(s) == 1)
		return (1);
	return (0);
}

int	ft_check_textures(t_list *s)
{
	int	fd;

	fd = open(s->no_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->no_arr[1]), 1);
	fd = open(s->so_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->so_arr[1]), 1);
	fd = open(s->we_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->we_arr[1]), 1);
	fd = open(s->ea_arr[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s is an invalid texture\n", s->ea_arr[1]), 1);
	return (0);
}

int	ft_check_map_args(t_list *s)
{
	if (ft_arraylen(s->no_arr) != 2 || ft_arraylen(s->so_arr) != 2 || \
	ft_arraylen(s->we_arr) != 2 || ft_arraylen(s->ea_arr) != 2)
		return (printf("Error\nIncorrect arguments in texture path\n"), 1);
	if (ft_arraylen(s->floor) != 4 || ft_arraylen(s->celling) != 4)
		return (printf("Error\nIncorrect arguments in c/f path\n"), 1);
	return (0);
}

int	ft_check_map_double_jump_line_bis(t_list *s, int i)
{
	while (s->map2d && s->map2d[i])
	{
		if (s->map2d[i] == '\n')
		{
			i++;
			while (s->map2d[i] == ' ' || s->map2d[i] == '\t')
				i++;
			if (s->map2d[i] == '\n')
				return (printf("Error\nNo playable map\n"), -1);
		}
		if (s->map2d[i] != '\0')
			i++;
	}
	return (i);
}

int	ft_check_map_double_jump_line(t_list *s)
{
	int	i;

	i = 0;
	while (s->map2d && s->map2d[i])
	{
		while (s->map2d[i] == ' ' || s->map2d[i] == '\t')
			i++;
		if (s->map2d[i] != '1')
		{
			while (s->map2d[i] != '\n' && s->map2d[i] != '\0')
				i++;
			i++;
		}
		else
		{
			i = ft_check_map_double_jump_line_bis(s, i);
			if (i == -1)
				return (1);
		}
	}
	return (0);
}
