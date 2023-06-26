/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:42:21 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/30 11:52:47 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_exp_(int d)
{
	int	c;

	c = 1;
	while (d > 0)
	{
		c = c * 10;
		d--;
	}
	return (c);
}

void	ft_write_nums(int n, int d, int fd)
{
	int		t;
	int		e;
	char	s;

	while (d >= 0)
	{
		e = ft_exp_(d);
		t = n / e;
		n = n - (e * t);
		s = t + 48;
		write(fd, &s, 1);
		d--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		d;
	int		n2;

	if (n == 0)
		write(fd, &"0", 1);
	else if (n == -2147483648)
		write(fd, &"-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, &"-", 1);
			n = n * (-1);
		}
		d = 0;
		n2 = n;
		while (n2 > 9)
		{
			n2 = n2 / 10;
			d++;
		}
		ft_write_nums(n, d, fd);
	}
}
