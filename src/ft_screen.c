/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:09:58 by iportill          #+#    #+#             */
/*   Updated: 2024/02/15 18:16:56 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_set_player_coord(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->pam[i])
	{
		j = 0;
		while (d->pam[i][j])
		{
			if (d->pam[i][j] == 'N' || d->pam[i][j] == 'W' || \
			d->pam[i][j] == 'E' || d->pam[i][j] == 'S')
			{
				d->px = i + 0.5;
				d->py = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_key_hook_release(int keycode, t_data *d)//quitar seguramente
{
	if (keycode == RIGHTKEY)
		d->rotate = 0;
	if (keycode == LEFTKEY)
		d->rotate = 0;
	if (keycode == UPKEY || keycode == W)
		d->walk_forw = 0;
	if (keycode == DOWNKEY || keycode == S)
		d->walk_back = 0;
	if (keycode == A)
		d->walk_left = 0;
	if (keycode == D)
		d->walk_right = 0;
	return (0);
}

int	ft_key_press(int keycode, t_data *d)
{
	if (keycode == RIGHTKEY)
		d->rotate = 2;
	if (keycode == LEFTKEY)
		d->rotate = 1;
	if (keycode == UPKEY || keycode == W)
		d->walk_forw = 1;
	if (keycode == DOWNKEY || keycode == S)
		d->walk_back = 1;
	if (keycode == A)
		d->walk_left = 1;
	if (keycode == D)
		d->walk_right = 1;
	if (keycode == Q || keycode == ESC)
		ft_free_struc_d(d);
	return (0);
}

void	ft_charge_image(t_data *d)
{
	int	x;

	x = 300;
	d->n.img = mlx_xpm_file_to_image(d->mlx, d->texture_s, &x, &x);
	d->n.addr = (int *) mlx_get_data_addr(d->n.img, &d->n.bits_per_pixel,
			&d->n.line_length, &d->n.endian);
	d->s.img = mlx_xpm_file_to_image(d->mlx, d->texture_n, &x, &x);
	d->s.addr = (int *) mlx_get_data_addr(d->s.img, &d->s.bits_per_pixel,
			&d->s.line_length, &d->s.endian);
	d->e.img = mlx_xpm_file_to_image(d->mlx, d->texture_w, &x, &x);
	d->e.addr = (int *) mlx_get_data_addr(d->e.img, &d->e.bits_per_pixel,
			&d->e.line_length, &d->e.endian);
	d->w.img = mlx_xpm_file_to_image(d->mlx, d->texture_e, &x, &x);
	d->w.addr = (int *) mlx_get_data_addr(d->w.img, &d->w.bits_per_pixel,
			&d->w.line_length, &d->w.endian);
}

void	ft_screen(t_data *d)
{
	ft_set_player_coord(d);
	d->mlx = mlx_init();
	ft_charge_image(d);
	d->mlx_win = mlx_new_window(d->mlx, X_SIZE_SCREEN, Y_SIZE_SCREEN, "cube3D");
	d->img = mlx_new_image(d->mlx, X_SIZE_SCREEN, Y_SIZE_SCREEN);
	d->addr = mlx_get_data_addr \
		(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
	mlx_loop_hook(d->mlx, ft_move, d);
	mlx_hook(d->mlx_win, 2, (1L << 0), ft_key_press, d);
	mlx_hook(d->mlx_win, 3, (1L << 1), ft_key_hook_release, d);
	mlx_hook(d->mlx_win, 17, 0, ft_free_struc_d, d);
	mlx_loop(d->mlx);
}
