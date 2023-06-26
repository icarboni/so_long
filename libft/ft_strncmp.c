/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:16:28 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:47:50 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			c;
	unsigned char	*d1;
	unsigned char	*d2;

	c = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while ((d1[c] != '\0' || d2[c] != '\0') && c < n)
	{
		if (d1[c] > d2[c])
		{
			return (1);
		}
		else if (d1[c] < d2[c])
			return (-1);
		c++;
	}
	return (0);
}
