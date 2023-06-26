/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:01:03 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:51:24 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*d;
	int		i;

	d = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char) c)
			d = (char *) &str[i];
		i++;
	}
	if (d != 0)
		return (d);
	if ((unsigned char) c == 0)
	{
		d = (char *) &str[i];
		return (d);
	}
	return (NULL);
}
