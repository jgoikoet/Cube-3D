/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:34 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 18:02:57 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_initial_position(t_list *s)
{
	if (s->pj_init_nsew != 'N' && s->pj_init_nsew != 'S' && \
	s->pj_init_nsew != 'W' && s->pj_init_nsew != 'E')
		return (printf("Error\nThe map haven't initial position\n"), 1);
	return (0);
}

int	ft_check_new_playable_map_bis(t_list *s, char c, int i, int e)
{
	if ((i == 0 || i == (s->playable_array_len - 1)) && \
	(s->new_playable_map[i][e] == c))
		return (1);
	if ((e == 0 || e == (s->playable_str_len - 1)) && \
	(s->new_playable_map[i][e] == c))
		return (1);
	if (s->new_playable_map[i][e] == c)
	{
		if ((i != 0) && (s->new_playable_map[i - 1][e] == '-'))
			return (1);
		else if ((i != s->playable_str_len) && \
		(s->new_playable_map[i + 1][e] == '-'))
			return (1);
		else if ((e != 0) && (s->new_playable_map[i][e - 1] == '-'))
			return (1);
		else if ((i != s->playable_array_len) && \
		(s->new_playable_map[i][e + 1] == '-'))
			return (1);
	}
	return (0);
}

int	ft_check_new_playable_map_its_playable(t_list *s, char c)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (s->new_playable_map && s->new_playable_map[i])
	{
		e = 0;
		while (s->new_playable_map[i][e])
		{
			if (ft_check_new_playable_map_bis(s, c, i, e) == 1)
			{
				printf("Error\nNo playable maps\n");
				return (1);
			}
			e++;
		}
		i++;
	}
	return (0);
}

int	ft_check_player_in_new_map(t_list *s)
{
	if (ft_check_new_playable_map_its_playable(s, s->pj_init_nsew) == 1)
		return (printf("Error in ft_check_new_playable_map_its_playable %c\n", \
		s->pj_init_nsew), 1);
	return (0);
}

int	ft_checks(t_list *s)
{
	if (ft_check_map_args(s) == 1)
		return (1);
	if (ft_check_chars_in_playable_map(s) == 1)
		return (1);
	if (ft_check_textures(s) == 1)
		return (1);
	if (ft_check_map_double_jump_line(s) == 1)
		return (1);
	if (ft_check_new_playable_map_its_playable(s, '0') == 1)
		return (1);
	if (ft_check_line7(s->map3d[6]) == 1)
		return (1);
	if (ft_check_player_in_new_map(s) == 1)
		return (1);
	if (ft_check_floor_cellig_values(s) == 1)
		return (1);
	return (0);
}
