/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:43:38 by icarboni          #+#    #+#             */
/*   Updated: 2023/07/06 20:05:37 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

// A = 0
// S = 1
// D = 2
// W = 13

void	ft_move_right(t_data *x)
{
	if (x->map.map_s[x->map.y][x->map.x + 1] != '1')
	{
		if (x->map.map_s[x->map.y][x->map.x] == 'E')
			ft_put_image(x->lib, x->imgs.door, x->map.x, x->map.y);
		else
			ft_put_image(x->lib, x->imgs.bg, x->map.x, x->map.y);
		x->map.num_mov++;
		ft_printf("%d ", x->map.num_mov);
		x->map.x++;
		ft_put_image(x->lib, x->imgs.nyan, x->map.x, x->map.y);
		if (x->map.map_s[x->map.y][x->map.x] == 'C')
		{
			x->map.map_s[x->map.y][x->map.x] = '0';
			x->map.collected++;
		}
		else if (x->map.map_s[x->map.y][x->map.x] == 'E'
			&& (x->map.collected == x->map.num_c))
			ft_exit(x, 0);
	}
}

void	ft_move_left(t_data *x)
{
	if (x->map.map_s[x->map.y][x->map.x - 1] != '1')
	{
		if (x->map.map_s[x->map.y][x->map.x] == 'E')
			ft_put_image(x->lib, x->imgs.door, x->map.x, x->map.y);
		else
			ft_put_image(x->lib, x->imgs.bg, x->map.x, x->map.y);
		x->map.num_mov++;
		ft_printf("%d ", x->map.num_mov);
		x->map.x--;
		ft_put_image(x->lib, x->imgs.nyan, x->map.x, x->map.y);
		if (x->map.map_s[x->map.y][x->map.x] == 'C')
		{
			x->map.map_s[x->map.y][x->map.x] = '0';
			x->map.collected++;
		}
		else if (x->map.map_s[x->map.y][x->map.x] == 'E'
			&& (x->map.collected == x->map.num_c))
			ft_exit(x, 0);
	}
}

void	ft_move_up(t_data *x)
{
	if (x->map.map_s[x->map.y - 1][x->map.x] != '1')
	{
		if (x->map.map_s[x->map.y][x->map.x] == 'E')
			ft_put_image(x->lib, x->imgs.door, x->map.x, x->map.y);
		else
			ft_put_image(x->lib, x->imgs.bg, x->map.x, x->map.y);
		x->map.num_mov++;
		ft_printf("%d ", x->map.num_mov);
		x->map.y--;
		ft_put_image(x->lib, x->imgs.nyan, x->map.x, x->map.y);
		if (x->map.map_s[x->map.y][x->map.x] == 'C')
		{
			x->map.map_s[x->map.y][x->map.x] = '0';
			x->map.collected++;
		}
		else if (x->map.map_s[x->map.y][x->map.x] == 'E'
			&& (x->map.collected == x->map.num_c))
			ft_exit(x, 0);
	}
}

void	ft_move_down(t_data *x)
{
	if (x->map.map_s[x->map.y + 1][x->map.x] != '1')
	{
		if (x->map.map_s[x->map.y][x->map.x] == 'E')
			ft_put_image(x->lib, x->imgs.door, x->map.x, x->map.y);
		else
			ft_put_image(x->lib, x->imgs.bg, x->map.x, x->map.y);
		x->map.num_mov++;
		ft_printf("%d ", x->map.num_mov);
		x->map.y++;
		ft_put_image(x->lib, x->imgs.nyan, x->map.x, x->map.y);
		if (x->map.map_s[x->map.y + 1][x->map.x] == 'C')
		{
			x->map.map_s[x->map.y + 1][x->map.x] = '0';
			x->map.collected++;
		}
		else if (x->map.map_s[x->map.y + 1][x->map.x] == 'E'
			&& (x->map.collected == x->map.num_c))
			ft_exit(x, 0);
	}
}

int	key_hook(int keycode, t_data *x)
{
	if (keycode == 53 || keycode == 33)
		ft_exit(x, 0);
	else if (keycode == 0)
		ft_move_left(x);
	else if (keycode == 1)
		ft_move_down(x);
	else if (keycode == 2)
		ft_move_right(x);
	else if (keycode == 13)
		ft_move_up(x);
	return (0);
}
