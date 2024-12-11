/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:24:27 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/20 10:52:25 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_get_playable_map_strlen_arraylen(t_list *s)
{
	int	i;

	i = 0;
	while (s->playable_map && s->playable_map[s->playable_array_len])
	{
		i = ft_strlen(s->playable_map[s->playable_array_len]);
		if (i > s->playable_str_len)
			s->playable_str_len = i;
		s->playable_array_len++;
	}
	return (0);
}

int	ft_read_map(char **argv, t_list *s)
{
	char	*temp;
	int		fd;
	int		read_bytes;

	temp = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCant open file\n"), 1);
	while (1)
	{
		temp = ft_calloc(sizeof(char), 2);
		temp[1] = '\0';
		read_bytes = read(fd, temp, 1);
		s->map2d = ft_strjoin(s->map2d, temp);
		free(temp);
		if (read_bytes == 0)
			break ;
	}
	close(fd);
	return (0);
}

int	ft_maplen(char *s)
{
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nNose pudo abrir el archivo"), 0);
	while (read(fd, buffer, 1))
		i++;
	if (i < 1)
		return (close(fd), printf("Error\nMapa vacio.\n"), 0);
	return (close(fd), i);
}

void	ft_s_to_d(t_list *s, t_data *d)
{
	d->cell_rgb = s->cell_rgb;
	d->floor_rgb = s->floor_rgb;
	d->texture_n = ft_strdup(s->no_arr[1]);
	d->texture_s = ft_strdup(s->so_arr[1]);
	d->texture_w = ft_strdup(s->we_arr[1]);
	d->texture_e = ft_strdup(s->ea_arr[1]);
	ft_pam(d, s->new_playable_map);
	if (s->pj_init_nsew == 'N')
		d->angle_ini = 90;
	if (s->pj_init_nsew == 'S')
		d->angle_ini = 270;
	if (s->pj_init_nsew == 'E')
		d->angle_ini = 0;
	if (s->pj_init_nsew == 'W')
		d->angle_ini = 180;
}

int	main(int argc, char **argv)
{
	t_data	*d;
	t_list	*s;

	if (argc == 2)
	{
		s = ft_calloc(sizeof(t_list), 1);
		d = ft_calloc (sizeof(t_data), 1);
		if (ft_error(s, argv) == 1)
			return (free(d), 1);
		ft_s_to_d(s, d);
		ft_free_struc_s(s);
		ft_screen(d);
	}
	else
		printf("Error\nInvalid num of arguments\n");
	return (0);
}
