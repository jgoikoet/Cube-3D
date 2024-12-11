/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:09:02 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/19 12:43:56 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_set_texture_color(t_data *d, int j, int p)
{
	double	x;
	int		y;

	if (d->texture == 'x')
	{
		x = 300 * (d->ry - floor(d->ry));
		y = (300 * p) / j;
		return (d->active.addr[(300 * y) + (int)x]);
	}
	else if (d->texture == 'y')
	{
		x = 300 * (d->rx - floor(d->rx));
		y = (300 * p) / j;
		return (d->active.addr[(300 * y) + (int)x]);
	}
	return (0);
}

void	ft_create_line(t_data *d, int x)
{
	int	j;
	int	y;
	int	k;
	int	p;

	j = (int)(480 / d->dist);
	d->correct = j - 480;
	if (d->correct < 0)
		d->correct = 0;
	y = 0;
	while (y < (480 - j) / 2)
		my_mlx_pixel_put(d, x, y++, d->cell_rgb);
	k = y + j;
	p = 0;
	while (y < 480 && y < k)
	{
		my_mlx_pixel_put(d, x, y++, \
		ft_set_texture_color(d, j, p++ + (d->correct / 2)));
	}
	while (y < 480)
		my_mlx_pixel_put(d, x, y++, d->floor_rgb);
}

void	ft_walk(t_data *d)
{
	if (d->walk_forw == 1)
		ft_walk_forward(d);
	if (d->walk_back == 1)
		ft_walk_backward(d);
	if (d->walk_left == 1)
		ft_walk_left(d);
	if (d->walk_right == 1)
		ft_walk_right(d);
	ft_rotate (d);
}

int	ft_move(t_data *d)
{
	int	i;

	i = 749;
	d->angle = d->angle_ini - 33;
	while (i >= 0)
	{
		if (d->angle < 0)
			d->angle += 360;
		if (d->angle <= 90 && i >= 0)
			i = ft_move_q1(d, i);
		else if (d->angle <= 180 && i >= 0)
			i = ft_move_q2(d, i);
		else if (d->angle <= 270 && i >= 0)
			i = ft_move_q3(d, i);
		else if (d->angle <= 360 && i >= 0)
			i = ft_move_q4(d, i);
		if (d->angle_ini < 0)
			d->angle_ini += 360;
		else if (d->angle_ini > 360)
			d->angle_ini -= 360;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	ft_walk(d);
	return (0);
}
