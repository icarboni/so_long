/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:12:01 by icarboni          #+#    #+#             */
/*   Updated: 2023/05/15 20:43:08 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ddigits_count(double n)
{
	int	c;
	int	i;

	c = 0;
	while (n > 9)
	{
		n = n / 10;
		c++;
	}
	i = n;
	n = n - i;
	i = 0;
	while ((n - i) != 0)
	{
		n = n * 10;
		i = n;
		c++;
	}
	return (c);
}

int	ft_dexp(int d)
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

void	ft_dcount(double nb)
{
	int	d;
	int	e;
	int	t;

	d = ft_ddigits_count(nb);
	while (d >= 0)
	{
		e = ft_dexp(d);
		t = nb / e;
		nb = nb - (e * t);
		ft_putchar_(t + 48);
		d--;
	}
}

int	ft_dputnbr(double nb)
{
	int	neg;

	neg = 0;
	if (nb == 0)
	{
		ft_putchar_('0');
		return (1);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_('-');
			nb = nb * (-1);
			neg = 1;
		}
		ft_dcount(nb);
		return (ft_ddigits_count(nb) + 1 + neg);
	}
}
