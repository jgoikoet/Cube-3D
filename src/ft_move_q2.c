/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_q2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:53:27 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/14 18:06:02 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_check_contact_x(t_data *d)
{
	if (d->pam[(int)floor(d->rx - 1)][(int)floor(d->ry)] == '1')
	{
		d->active = d->e;
		d->contact = 1;
	}
}

static void	ft_check_contact_y(t_data *d)
{
	if (d->pam[(int)floor(d->rx)][(int)floor(d->ry)] == '1')
	{
		d->active = d->s;
		d->contact = 1;
	}
}

static void	ft_ray_x(t_data *d)
{
	d->rx -= d->dis_x;
	d->ry += ((d->dis_x / cos(d->angle_rad)) * sin(d->angle_rad));
	if (ceil(d->ry) == d->ry)
		d->dis_y = 1;
	else
		d->dis_y = ceil(d->ry) - d->ry;
	d->dis_x = 1;
	d->texture = 'x';
	ft_check_contact_x(d);
}

static void	ft_ray_y(t_data *d)
{
	d->ry += d->dis_y;
	d->rx -= ((d->dis_y / sin(d->angle_rad)) * cos(d->angle_rad));
	if (floor(d->rx) == d->rx)
		d->dis_x = 1;
	else
		d->dis_x = d->rx - floor(d->rx);
	d->dis_y = 1;
	d->texture = 'y';
	ft_check_contact_y(d);
}

int	ft_move_q2(t_data *d, int i)
{
	d->angle = 180 - d->angle;
	while (i >= 0 && (d->angle) >= 0)
	{
		d->rx = d->px;
		d->ry = d->py;
		d->contact = 0;
		d->angle_rad = d->angle * M_PI / 180.0;
		d->dis_x = d->rx - floor(d->rx);
		d->dis_y = ceil(d->ry) - d->ry;
		while (d->contact == 0)
		{
			if (d->dis_x / cos(d->angle_rad) < d->dis_y / sin(d->angle_rad))
				ft_ray_x(d);
			else
				ft_ray_y(d);
		}
		d->ang_dist_rad = ((d->angle) - (90 - d->angle_ini)) * M_PI / 180;
		d->dist = ((d->px - d->rx) / cos(d->angle_rad)) * sin (d->ang_dist_rad);
		ft_create_line(d, i);
		d->angle -= 0.088;
		i--;
	}
	if (d->angle < 0)
		d->angle = 180.1 + (-d->angle);
	return (i);
}
