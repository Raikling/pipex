/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:58:20 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/11/05 11:59:59 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	l;
	size_t			i;

	p = (unsigned char *)s;
	l = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (p[i] == l)
			return ((void *)&p[i]);
		i++;
	}
	return (0);
}
