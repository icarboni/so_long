/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:46:14 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:16:27 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			c;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	c = 0;
	if (n == 0)
		return (0);
	while (d1[c] == d2[c] && c < n)
	{
		c++;
		if ((c) == n)
			return (0);
	}
	return (d1[c] - d2[c]);
}
