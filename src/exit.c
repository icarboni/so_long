/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:24:15 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/28 18:52:44 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	ft_errors(int error)
{
	if (error == 1)
		ft_printf("Error\nThe number of arguments is not valid.");
	if (error == 2)
		ft_printf("Error\nThe map extension is not correct.");
	if (error == 3)
		ft_printf("Error\nWhile allocating memory.");
	if (error == 4)
		ft_printf("Error\nThe map is not rectangular.");
	if (error == 5)
		ft_printf("Error\nThe map includes invalid symbols.");
	if (error == 6)
		ft_printf("Error\nThe number of elements in the map is invalid.");
	if (error == 7)
		ft_printf("Error\nThe map is not surrounded by walls.");
	if (error == 8)
		ft_printf("Error\nObjects or exit is not reachable.");
	if (error == 9)
		ft_printf("Error\nThe map file does not exist.");
}

int	ft_exit(t_data *x, int error)
{
	int	i;

	i = -1;
	if (error == 0)
	{
		free(x->lib.img);
		free(x->lib.addr);
		ft_printf("\nExit");
	}
	else
		ft_errors(error);
	if (error > 3 || error == 0)
	{
		while (++i < x->map.rows)
		{
			free(x->map.map_s[i]);
			free(x->map.flood_fill[i]);
		}
		free(x->map.map_s);
		free(x->map.flood_fill);
	}
	exit(0);
	return (0);
}
