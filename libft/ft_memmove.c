/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:38:05 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/27 18:15:43 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t		i;
	char		*str11;
	char		*str22;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	str11 = (char *) str1;
	str22 = (char *) str2;
	i = 0;
	if (str1 > str2)
	{
		while (n-- > 0)
		{
			str11[n] = str22[n];
		}
	}
	else
	{
		while (i < n)
		{
			str11[i] = str22[i];
			i++;
		}	
	}
	return (str1);
}
