/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:49:53 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 19:26:41 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	main(int argc, char **argv)
{
	t_data	x;

	ft_read_map(argc, argv[1], &x);
	x.map.px = 64;
	x.map.x = -1;
	x.map.y = -1;
	x.lib.mlx = mlx_init();
	x.lib.win = mlx_new_window(x.lib.mlx,
			(x.map.cols * 64), (x.map.rows * 64), "so_long");
	x.lib.img = mlx_new_image(x.lib.mlx, (x.map.cols * 64), (x.map.rows * 64));
	x.lib.addr = mlx_get_data_addr(x.lib.img, &x.lib.bits_per_pixel,
			&x.lib.line_length, &x.lib.endian);
	ft_assign_imgs(&x);
	ft_map_fill(&x);
	x.map.num_mov = 0;
	x.map.collected = 0;
	mlx_loop_hook(x.lib.mlx, ft_render, &x);
	mlx_loop(x.lib.mlx);
}

int	ft_render(t_data *x)
{
	mlx_key_hook(x->lib.win, key_hook, x);
	mlx_hook(x->lib.win, 17, 1L << 17, ft_exit, x);
	return (0);
}
