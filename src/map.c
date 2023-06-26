/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 03:09:04 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 18:27:39 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

// Error 1: the number of arguments is not valid.
// Error 2: the map extension is not correct.
// Error 3: Malloc error allocating map. ---free map
// Error 4: the map is not rectangular.
// Error 5: the map includes invalid symbols.
// Error 6: the number of elements in the map is invalid.
// Error 7: the map is not surrounded by walls.

void	ft_read_map(int argc, char *map_file, t_data *x)
{
	if (argc != 2)
		ft_exit(x, 1);
	ft_check_extension(map_file, x);
	x->map.rows = ft_count_lines(map_file);
	x->map.map_s = (char **)malloc(sizeof(char *) * (x->map.rows + 1));
	x->map.flood_fill = (char **)malloc(sizeof(char *) * (x->map.rows + 1));
	if (!x->map.map_s || !x->map.flood_fill)
		ft_exit(x, 3);
	if (ft_create_map(map_file, x->map.map_s))
		ft_exit(x, 9);
	ft_create_map(map_file, x->map.flood_fill);
	ft_check_lenght(&x->map, x);
	ft_check_map(&x->map, x);
	ft_check_walls(&x->map, x);
	ft_check_path(x);
}

int	ft_create_map(char *map_file, char **map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		if (map[i][ft_strlen(line) - 1] == '\n')
			map[i][ft_strlen(line) - 1] = 0;
		i++;
		line = get_next_line(fd);
	}
	free(line);
	map[i] = NULL;
	close(fd);
	return (0);
}

int	ft_count_lines(char *map_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

void	ft_check_extension(char *map_name, t_data *x)
{
	int	l;

	l = ft_strlen(map_name);
	if (map_name[l - 1] != 'r'
		|| map_name[l - 2] != 'e'
		|| map_name[l - 3] != 'b'
		|| map_name[l - 4] != '.')
		ft_exit(x, 2);
}
