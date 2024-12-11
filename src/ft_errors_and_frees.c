/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_frees.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:27:02 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/19 18:09:25 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_array(char ***s)
{
	int	i;

	i = 0;
	if (*s)
	{
		while ((*s)[i])
			free((*s)[i++]);
		free (*s);
	}
	*s = NULL;
}

void	ft_free_struc_s(t_list *s)
{
	ft_free_array(&s->new_playable_map);
	ft_free_array(&s->map_settings);
	free(s->map2d);
	free(s->playable_map);
	free(s->floor_int_arr);
	free(s->celling_int_arr);
	ft_free_array(&s->so_arr);
	ft_free_array(&s->no_arr);
	ft_free_array(&s->map3d);
	ft_free_array(&s->we_arr);
	ft_free_array(&s->ea_arr);
	ft_free_array(&s->floor);
	ft_free_array(&s->celling);
	free(s);
}

int	ft_free_struc_d(t_data *d)
{
	ft_free_array(&d->pam);
	free(d->texture_n);
	free(d->texture_s);
	free(d->texture_e);
	free(d->texture_w);
	free(d);
	printf("\n---------------- GAME OVER ----------------\n\n");
	exit(0);
}

int	ft_error(t_list *s, char **argv)
{
	int		len;

	len = ft_strlen(argv[1]);
	if (len <= 9)
		return (printf("Error\nNot valid file\n"), 1);
	if ((argv[1][len - 1] != 'b') || (argv[1][len - 2] != 'u') \
	|| (argv[1][len - 3] != 'c') || (argv[1][len - 4] != '.'))
		return (free(s), printf("Error\nWrong file extension\n"), 1);
	if (ft_get_maps(s, argv) == 1)
		return (ft_free_struc_s(s), 1);
	if (ft_floor_cell(s) == 1)
		return (ft_free_struc_s(s), 1);
	if (ft_checks(s) == 1)
		return (ft_free_struc_s(s), 1);
	return (0);
}
