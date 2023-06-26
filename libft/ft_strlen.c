/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:55:43 by icarboni          #+#    #+#             */
/*   Updated: 2022/09/29 17:47:28 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int					c;
	unsigned char		*str2;

	str2 = (unsigned char *) str;
	c = 0;
	while (str2[c] != '\0')
		c++;
	return (c);
}
