/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:08:53 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/15 20:44:07 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digits_count(int n)
{
	int	c;

	c = 0;
	while (n > 9)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int	ft_exp(int d)
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

void	ft_count(int nb)
{
	int	d;
	int	e;
	int	t;

	d = ft_digits_count(nb);
	while (d >= 0)
	{
		e = ft_exp(d);
		t = nb / e;
		nb = nb - (e * t);
		ft_putchar_(t + 48);
		d--;
	}
}

int	ft_putnbr(int nb)
{
	int	neg;

	neg = 0;
	if (nb == 0)
	{
		ft_putchar_('0');
		return (1);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_('-');
			nb = nb * (-1);
			neg = 1;
		}
		ft_count(nb);
		return (ft_digits_count(nb) + 1 + neg);
	}
}
