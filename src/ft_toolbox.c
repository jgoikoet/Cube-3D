/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:44:33 by iportill          #+#    #+#             */
/*   Updated: 2024/02/19 18:19:50 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_no_so_we_ea_f_c_check(t_list *s)
{
	if (!s->no_arr || !s->so_arr || !s->we_arr || \
		!s->ea_arr || !s->floor || !s->celling)
		return (1);
	return (0);
}

int	ft_check_line7(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != ' ')
			return (printf("Error\nTrash in map settings\n"), 1);
		i++;
	}
	return (0);
}
