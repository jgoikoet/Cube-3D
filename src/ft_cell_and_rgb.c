/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_and_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:20 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 13:18:56 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_array_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'C' || s[i] == 'F' || (s[i] == 'N' && s[i + 1] == 'O' ) || \
		(s[i] == 'S' && s[i + 1] == 'O' ) || (s[i] == 'W' \
		&& s[i + 1] == 'E' ) || \
		(s[i] == 'E' && s[i + 1] == 'A' ))
			return (1);
		i++;
	}
	return (0);
}

int	ft_cell_atoi_array(t_list *s)
{
	int	i;
	int	e;

	i = 1;
	e = 0;
	while (s->celling[i])
		i++;
	s->cell_size = i -1;
	s->celling_int_arr = ft_calloc(sizeof(int *), (s->cell_size));
	if (s->celling_int_arr == NULL)
		return (1);
	i = 1;
	while (s->celling[i])
	{
		s->celling_int_arr[e] = ft_atoi(s->celling[i]);
		e++;
		i++;
	}
	return (0);
}

int	check_celling_numbers(t_list *s, int n)
{
	int	i;

	i = 0;
	while (s->celling[n][i])
	{
		if (s->celling[n][i] >= '0' && s->celling[n][i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_clean_celling(t_list *s)
{
	if (check_celling_numbers(s, 1) == 1)
		return (printf("Error\nincorrect ceiling first number\n"), 1);
	if (check_celling_numbers(s, 2) == 1)
		return (printf("Error\nincorrect ceiling second number\n"), 1);
	if (check_celling_numbers(s, 3) == 1)
		return (printf("Error\nincorrect ceiling third number\n"), 1);
	return (0);
}

int	ft_transf_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}
