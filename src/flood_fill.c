/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:21:41 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 17:39:23 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_flood(t_data *d, int y, int x)
{
	if (!(y < 1 || x < 1 || y > d->map.rows - 1 || x > d->map.cols - 1
			|| d->map.flood_fill[y][x] == '1'
		|| d->map.flood_fill[y][x] == 'T'))
	{
		d->map.flood_fill[y][x] = 'T';
		ft_flood(d, y + 1, x);
		ft_flood(d, y, x + 1);
		ft_flood(d, y - 1, x);
		ft_flood(d, y, x - 1);
	}
}

void	ft_check_path(t_data *d)
{
	int	x;
	int	y;

	ft_flood(d, d->map.initial_pos[0], d->map.initial_pos[1]);
	y = 0;
	while (y < d->map.rows - 1)
	{
		x = 0;
		while (x < d->map.cols)
		{
			if (d->map.flood_fill[y][x] == 'E'
				|| d->map.flood_fill[y][x] == 'C'
				|| d->map.flood_fill[y][x] == 'P')
				ft_exit(d, 8);
			x++;
		}
		y++;
	}
}
