/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:31:46 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/30 12:06:22 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_aux_(int *n, int *neg)
{
	int	d;
	int	n2;

	d = 0;
	if (*n < 0)
	{
		*neg = 1;
		*n = *n * (-1);
	}
	n2 = *n;
	while (n2 > 9)
	{
		n2 = n2 / 10;
		d++;
	}
	if (*neg == 1)
		d++;
	return (d);
}

static void	ft_write_res(char *res, int d, int n, int neg)
{
	int		t;
	int		e;
	int		i;
	int		f;

	i = 0;
	if (neg == 1)
		res[0] = '-';
	while ((i + neg) <= (d + neg))
	{
		e = 1;
		f = d - i - neg;
		while (f > 0)
		{
			e = e * 10;
			f--;
		}
		t = n / e;
		n = n - (e * t);
		res[i + neg] = t + 48;
		i++;
	}
	res[i] = '\0';
}

static int	ft_allocate(char **res, int size)
{
	*res = (char *)malloc(size * sizeof (char));
	if (*res == NULL)
		return (0);
	else
		return (1);
}

static char	*ft_special(int n, char **res)
{
	if (n == 0)
	{
		if (ft_allocate(res, 2) == 0)
			return (NULL);
		ft_strlcpy(*res, "0\0", 2);
	}
	else if (n == -2147483648)
	{
		if (ft_allocate(res, 12) == 0)
			return (NULL);
		ft_strlcpy(*res, "-2147483648\0", 12);
	}
	return (*res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		d;
	int		neg;

	neg = 0;
	res = NULL;
	if (n == 0 || n == -2147483648)
	{
		res = ft_special(n, &res);
		if (res == NULL)
			return (NULL);
	}
	else
	{
		d = ft_aux_(&n, &neg);
		if (ft_allocate(&res, d + 2) == 0)
			return (NULL);
		ft_write_res(res, d, n, neg);
	}
	return (res);
}
