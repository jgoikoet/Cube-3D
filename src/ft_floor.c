/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:46 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 18:36:34 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_floor_cellig_values(t_list *s)
{
	int	i;

	i = 0;
	while (i < s->cell_size)
	{
		if (s->celling_int_arr[i] > -1 && s->celling_int_arr[i] < 256)
			i++;
		else
			return (printf("Error\n%i is an incorrect number in ceiling", \
			s->celling_int_arr[i]), 1);
	}
	i = 0;
	while (i < s->floor_size)
	{
		if (s->floor_int_arr[i] > -1 && s->floor_int_arr[i] < 256)
			i++;
		else
			return (printf("Error\n%i is an incorrect number in floor", \
			s->floor_int_arr[i]), 1);
	}
	return (0);
}

int	ft_floor_atoi_array(t_list *s)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (s->floor[i])
		i++;
	s->floor_size = i -1;
	s->floor_int_arr = ft_calloc(sizeof(int *), (s->floor_size));
	if (s->floor_int_arr == NULL)
		return (1);
	i = 1;
	while (s->floor[i])
	{
		s->floor_int_arr[e] = ft_atoi(s->floor[i]);
		e++;
		i++;
	}
	return (0);
}

int	ft_check_floor_arr_int_numbers(t_list *s, int n)
{
	int	i;

	i = 0;
	while (s->floor[n][i])
	{
		if (s->floor[n][i] >= '0' && s->floor[n][i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_clean_floor(t_list *s)
{
	if (ft_check_floor_arr_int_numbers(s, 1) == 1)
		return (printf("Error\nincorrect floor first number\n"), 1);
	if (ft_check_floor_arr_int_numbers(s, 2) == 1)
		return (printf("Error\nincorrect floor second number\n"), 1);
	if (ft_check_floor_arr_int_numbers(s, 3) == 1)
		return (printf("Error\nincorrect floor third number\n"), 1);
	return (0);
}

int	ft_floor_cell(t_list *s)
{
	if (ft_get_pj_init_position(s) == 1)
		return (printf("Error in ft_get_pj_init_position\n"), 1);
	ft_parshing_map_args(s);
	if (ft_check_no_so_we_ea_f_c_check(s) == 1)
		return (printf("Error\nIncorrect value set\n"), 1);
	if (ft_clean_floor(s) == 1)
		return (1);
	if (ft_clean_celling(s) == 1)
		return (1);
	if (ft_floor_atoi_array(s) == 1)
		return (printf("Error reserving memory for d->floor_int_arr\n"), 1);
	if (ft_cell_atoi_array(s) == 1)
		return (printf("Error reserving memory for d->cell_int_arr\n"), 1);
	s->floor_rgb = ft_transf_rgb(s->floor_int_arr[0], \
	s->floor_int_arr[1], s->floor_int_arr[2]);
	s->cell_rgb = ft_transf_rgb(s->celling_int_arr[0], \
	s->celling_int_arr[1], s->celling_int_arr[2]);
	return (0);
}
