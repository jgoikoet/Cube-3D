/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:10:08 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 15:01:35 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_get_playable_map_bis(t_list *s, int i, int u)
{
	while (s->map3d[u])
	{
		u++;
	}
	s->playable_map = ft_calloc(sizeof(char *), u + 1);
	if (s->playable_map == NULL)
		return (1);
	u = 0;
	while (s->map3d[i])
	{
		s->playable_map[u] = s->map3d[i];
		u++;
		i++;
	}
	return (0);
}

int	ft_get_playable_map(t_list *s)
{
	int	i;
	int	e;
	int	u;

	i = 0;
	e = 0;
	u = 0;
	while (s->map3d[i])
	{
		e = 0;
		while (s->map3d[i][e] == ' ' || s->map3d[i][e] == '\t')
		{
			e++;
		}
		if (s->map3d[i][e] == '0' || s->map3d[i][e] == '1')
			break ;
		i++;
	}
	u = i;
	if (ft_get_playable_map_bis(s, i, u) == 1)
		return (printf("Error in ft_get_playable_map_bis\n"), 1);
	return (0);
}

int	ft_get_maps(t_list *s, char **argv)
{
	if (ft_read_map(argv, s) == 1)
		return (1);
	s->map3d = ft_split(s->map2d, '\n');
	if (s->map3d == NULL)
		return (printf("Error in ft_split: d->map3d == NULL\n"), 1);
	if (ft_arraylen(s->map3d) < 9)
		return (printf("Error\nNot playable map\n"));
	if (ft_clean_map3d_split(s) == 1)
		return (1);
	ft_get_playable_map(s);
	ft_get_playable_map_strlen_arraylen(s);
	ft_create_new_playable_map(s);
	return (0);
}

int	ft_get_pj_init_position_bis(t_list *s, int i, int e)
{
	if (s->playable_map[i][e] == 'N')
	{
		s->pj_init_nsew = s->playable_map[i][e];
		s->n++;
	}
	else if (s->playable_map[i][e] == 'S')
	{
		s->pj_init_nsew = s->playable_map[i][e];
		s->s++;
	}
	else if (s->playable_map[i][e] == 'E')
	{
		s->pj_init_nsew = s->playable_map[i][e];
		s->e++;
	}
	else if (s->playable_map[i][e] == 'W')
	{
		s->pj_init_nsew = s->playable_map[i][e];
		s->w++;
	}
	return (0);
}

int	ft_get_pj_init_position(t_list *s)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	if (s->playable_map == NULL)
		return (1);
	while (s->playable_map[i])
	{
		e = 0;
		while (s->playable_map[i][e])
		{
			if (ft_get_pj_init_position_bis(s, i, e) == 1)
				return (printf("Error in ft_get_pj_init_position_bis\n"), 1);
			else if (s->playable_map[i][e] != 'N' && \
			s->playable_map[i][e] != 'S'\
			&& s->playable_map[i][e] != 'E' && s->playable_map[i][e] != 'W' \
			&& s->playable_map[i][e] != '0' && s->playable_map[i][e] != '1'\
			&& s->playable_map[i][e] != ' ' && s->playable_map[i][e] != '\n')
				s->invalid_char++;
			e++;
		}
		i++;
	}
	return (0);
}
