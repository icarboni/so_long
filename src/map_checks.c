/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:54:11 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 17:39:33 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

// num[0] free space
// num[1] walls
// num[2] collectables
// num[3] exit
// num[4] player

void	ft_check_char(int num[5], char c, t_data *x)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c)
		ft_exit(x, 5);
	else if (c == '0')
		num[0]++;
	else if (c == '1')
		num[1]++;
	else if (c == 'C')
		num[2]++;
	else if (c == 'E')
		num[3]++;
	else if (c == 'P')
		num[4]++;
}

void	ft_check_map(t_map *map, t_data *x)
{
	int	i;
	int	j;
	int	len;
	int	num[5];

	i = 0;
	while (i++ < 5)
		num[i] = 0;
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		len = ft_strlen(map->map_s[i]);
		while (++j < len)
		{
			ft_check_char(num, map->map_s[i][j], x);
			if (map->map_s[i][j] == 'P')
				ft_set_initial_pos(map, i, j);
		}
	}
	map->num_c = num[2];
	if (num[3] != 1 || num[2] == 0 || num[4] != 1)
		ft_exit(x, 6);
}

void	ft_set_initial_pos(t_map *map, int i, int j)
{
	map->initial_pos[0] = i;
	map->initial_pos[1] = j;
}

void	ft_check_lenght(t_map *map, t_data *x)
{
	int	i;

	i = 1;
	map->cols = ft_strlen(map->map_s[0]);
	while (i < map->rows)
	{
		if (ft_strlen(map->map_s[i]) != map->cols)
			ft_exit(x, 4);
		i++;
	}
}

void	ft_check_walls(t_map *map, t_data *x)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		if ((i == 0) || (i == map->rows - 1))
		{
			j = 0;
			while (j < map->cols)
			{
				if (map->map_s[i][j] != '1')
					ft_exit(x, 7);
				j++;
			}
		}
		else if (map->map_s[i][0] != '1' || map->map_s[i][map->cols - 1] != '1')
			ft_exit(x, 7);
		i++;
	}
}
