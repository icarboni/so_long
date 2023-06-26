/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:14:14 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/28 13:16:38 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*src;
	int		len;
	int		c;

	c = 0;
	src = (char *) s;
	len = ft_strlen(src);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (src[c] != '\0')
	{
		res[c] = src[c];
		c++;
	}
	res[c] = '\0';
	return (res);
}
