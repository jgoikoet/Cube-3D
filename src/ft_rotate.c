/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:04:24 by jgoikoet          #+#    #+#             */
/*   Updated: 2024/02/15 18:14:58 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_pam(t_data *d, char **map)
{
	int		len;
	int		slen;
	int		i;
	int		j;
	int		k;

	len = 0;
	while (map[0][len])
		len++;
	slen = 0;
	while (map[slen])
		slen++;
	d->pam = malloc (sizeof(char *) * (len + 1));
	d->pam[len] = NULL;
	i = 0;
	while (i < len)
	{
		k = 0;
		j = slen - 1;
		d->pam[i] = malloc (sizeof(char) * (slen + 1));
		while (j >= 0)
			d->pam[i][k++] = map[j--][i];
		d->pam[i][k] = '\0';
		i++;
	}
}

void	ft_rotate(t_data *d)
{
	if (d->rotate == 1)
		d->angle_ini += ROTATE_STEP;
	else if (d->rotate == 2)
		d->angle_ini -= ROTATE_STEP;
}
