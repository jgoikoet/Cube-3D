/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parshing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:10:13 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 18:22:50 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_parshing_map_args(t_list *s)
{
	int	i;

	i = 0;
	while (s->map_settings[i] && i < 6)
	{
		s->map_date = ft_dual_split(s->map_settings[i], ' ', ',');
		if (ft_strcmp(s->map_date[0], "NO") == 0)
			s->no_arr = s->map_date;
		else if (ft_strcmp(s->map_date[0], "SO") == 0)
			s->so_arr = s->map_date;
		else if (ft_strcmp(s->map_date[0], "WE") == 0)
			s->we_arr = s->map_date;
		else if (ft_strcmp(s->map_date[0], "EA") == 0)
			s->ea_arr = s->map_date;
		else if (ft_strcmp(s->map_date[0], "F") == 0)
			s->floor = s->map_date;
		else if (ft_strcmp(s->map_date[0], "C") == 0)
			s->celling = s->map_date;
		else
			ft_free_array(&s->map_date);
		i++;
	}
	return ;
}

int	ft_clean_map3d_split_bis(t_list *s, int i, int count)
{
	while (s->map3d[i])
	{
		count = count + ft_array_check(s->map3d[i]);
		i++;
	}
	if (count != 6)
		return \
		(printf("Error\nIncorrect number of arguments in map_settings\n"), 1);
	s->map_settings = ft_calloc(sizeof(char *), count + 1);
	if (s->map_settings == NULL)
		return (1);
	return (0);
}

int	ft_clean_map3d_split(t_list *s)
{
	int	i;
	int	e;
	int	count;

	i = 0;
	e = 0;
	count = 0;
	if (ft_clean_map3d_split_bis(s, i, count) == 1)
		return (1);
	if (s->map_settings == NULL)
		return (1);
	i = 0;
	while (s->map3d[i])
	{
		if (ft_array_check(s->map3d[i]) == 1)
		{
			s->map_settings[e] = ft_strdup(s->map3d[i]);
			e++;
			i++;
		}
		else
			i++;
	}
	return (0);
}

int	ft_create_new_playable_map(t_list *s)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	s->new_playable_map = ft_calloc(sizeof(char *), \
	(s->playable_array_len + 1));
	if (s->new_playable_map == NULL)
		return (1);
	while (s->playable_map[i])
	{
		s->new_playable_map[i] = ft_calloc(sizeof(char), \
		(s->playable_str_len + 1));
		if (s->new_playable_map[i] == NULL)
			return (1);
		i++;
	}
	if (ft_calloc_for_new_playable_map(s, e) == 1)
		return (1);
	return (0);
}

int	ft_calloc_for_new_playable_map(t_list *s, int e)
{
	int	i;

	i = 0;
	while (s->playable_map[i])
	{
		e = 0;
		while (s->playable_map[i][e])
		{
			if (s->playable_map[i][e] == ' ')
				s->new_playable_map[i][e] = '-';
			else
				s->new_playable_map[i][e] = s->playable_map[i][e];
			e++;
		}
		while (e < s->playable_str_len)
		{
			s->new_playable_map[i][e] = '-';
			e++;
		}
		i++;
	}
	return (0);
}
