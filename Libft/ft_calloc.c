/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:39:42 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/11/15 16:11:34 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && nmemb > ((size_t) -1) / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == 0)
		return (0);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
