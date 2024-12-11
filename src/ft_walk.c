/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:24 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/15 18:25:01 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_walk_colision(t_data *d, double x, double y)
{
	if (d->pam[(int)x][(int)y] != '1')
	{
		d->px = x;
		d->py = y;
	}
}

void	ft_walk_left(t_data *d)
{
	d->x = 0.0;
	d->y = 0.0;
	if (d->angle_ini <= 90)
	{
		d->x = d->px - (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * cos (d->angle_ini * M_PI / 180.0));
	}
	else if (d->angle_ini <= 180)
	{
		d->x = d->px - (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * sin ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		d->x = d->px + (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * cos ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		d->x = d->px + (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * sin ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, d->x, d->y);
}

void	ft_walk_right(t_data *d)
{
	d->x = 0.0;
	d->y = 0.0;
	if (d->angle_ini <= 90)
	{
		d->x = d->px + (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
		d->y = d->py - WALK_STEP * cos (d->angle_ini * M_PI / 180.0);
	}
	else if (d->angle_ini <= 180)
	{
		d->x = d->px + (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * sin ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		d->x = d->px - (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * cos ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		d->x = d->px - (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * sin ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, d->x, d->y);
}

void	ft_walk_forward(t_data *d)
{
	d->x = 0.0;
	d->y = 0.0;
	if (d->angle_ini <= 90)
	{
		d->x = d->px + (WALK_STEP * cos (d->angle_ini * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
	}
	else if (d->angle_ini <= 180)
	{
		d->x = d->px - (WALK_STEP * sin ((d->angle_ini - 90) * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		d->x = d->px - (WALK_STEP * cos ((d->angle_ini - 180) * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		d->x = d->px + (WALK_STEP * sin ((d->angle_ini - 270) * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, d->x, d->y);
}

void	ft_walk_backward(t_data *d)
{
	d->x = 0.0;
	d->y = 0.0;
	if (d->angle_ini <= 90)
	{
		d->x = d->px - (WALK_STEP * cos (d->angle_ini * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * sin (d->angle_ini * M_PI / 180.0));
	}
	else if (d->angle_ini <= 180)
	{
		d->x = d->px + (WALK_STEP * sin ((d->angle_ini - 90) * M_PI / 180.0));
		d->y = d->py - (WALK_STEP * cos ((d->angle_ini - 90) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 270)
	{
		d->x = d->px + (WALK_STEP * cos ((d->angle_ini - 180) * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * sin ((d->angle_ini - 180) * M_PI / 180.0));
	}
	else if (d->angle_ini <= 360)
	{
		d->x = d->px - (WALK_STEP * sin ((d->angle_ini - 270) * M_PI / 180.0));
		d->y = d->py + (WALK_STEP * cos ((d->angle_ini - 270) * M_PI / 180.0));
	}
	ft_walk_colision(d, d->x, d->y);
}
