/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:09:44 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 18:09:29 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_assign_imgs(t_data *x)
{
	int	px;

	px = x->map.px;
	x->imgs.bg = mlx_xpm_file_to_image(x->lib.mlx, "img/bg.xpm", &px, &px);
	x->imgs.nyan = mlx_xpm_file_to_image(x->lib.mlx, "img/nyan.xpm", &px, &px);
	x->imgs.wall = mlx_xpm_file_to_image(x->lib.mlx, "img/wall.xpm", &px, &px);
	x->imgs.obj = mlx_xpm_file_to_image(x->lib.mlx, "img/obj.xpm", &px, &px);
	x->imgs.door = mlx_xpm_file_to_image(x->lib.mlx, "img/door.xpm", &px, &px);
}

void	ft_put_image(t_lib l, void *im, int j, int i)
{
	mlx_put_image_to_window(l.mlx, l.win, im, j * 64, i * 64);
}

void	ft_char_cases(t_data *x, int i, int j)
{
	if (x->map.map_s[i][j] == 'P' && (x->map.x == -1 && x->map.y == -1))
	{
		ft_put_image(x->lib, x->imgs.nyan, j, i);
		x->map.x = j;
		x->map.y = i;
	}
	else if (x->map.map_s[i][j] == '1')
		ft_put_image(x->lib, x->imgs.wall, j, i);
	else if (x->map.map_s[i][j] == 'E')
		ft_put_image(x->lib, x->imgs.door, j, i);
	else if (x->map.map_s[i][j] == 'C')
		ft_put_image(x->lib, x->imgs.obj, j, i);
	else
		ft_put_image(x->lib, x->imgs.bg, j, i);
}

void	ft_map_fill(t_data *x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < x->map.rows)
	{
		j = -1;
		while (++j < x->map.cols)
			ft_char_cases(x, i, j);
	}
	if (x->map.x != -1 && x->map.y != -1)
		ft_put_image(x->lib, x->imgs.nyan, x->map.x, x->map.y);
}
