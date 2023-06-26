/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:50:25 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 19:26:51 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/ft_printf/ft_printf.h"

typedef struct s_imgs {
	void	*bg;
	void	*nyan;
	void	*wall;
	void	*obj;
	void	*door;
}	t_imgs;

typedef struct s_map {
	int		px;
	int		cols;
	int		rows;
	char	**map_s;
	char	**flood_fill;
	int		x;
	int		y;
	int		num_c;
	int		num_mov;
	int		collected;
	int		initial_pos[2];
}	t_map;

typedef struct s_lib {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_lib;

typedef struct s_data {
	t_lib	lib;
	t_map	map;
	t_imgs	imgs;
}	t_data;

// so_long.c
int		main(int argc, char **argv);
int		ft_render(t_data *x);

// map.c
void	ft_read_map(int argc, char *map_file, t_data *x);
int		ft_create_map(char *map_file, char **map);
int		ft_count_lines(char *map_file);
void	ft_check_extension(char *map_name, t_data *x);

// map_checks.c
void	ft_check_map(t_map *map, t_data *x);
void	ft_check_char(int num[5], char c, t_data *x);
void	ft_check_lenght(t_map *map, t_data *x);
void	ft_check_walls(t_map *map, t_data *x);
void	ft_set_initial_pos(t_map *map, int i, int j);

// images.c
void	ft_assign_imgs(t_data *x);
void	ft_put_image(t_lib l, void *im, int i, int j);
void	ft_char_cases(t_data *x, int i, int j);
void	ft_map_fill(t_data *x);

// keys.c
void	ft_move_right(t_data *x);
void	ft_move_left(t_data *x);
void	ft_move_up(t_data *x);
void	ft_move_down(t_data *x);
int		key_hook(int keycode, t_data *x);

// flood_fill.c
void	ft_flood(t_data *d, int x, int y);
void	ft_check_path(t_data *d);

// exit.c
void	ft_errors(int error);
int		ft_exit(t_data *x, int error);

#endif