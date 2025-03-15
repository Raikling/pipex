/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:26:06 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/11/09 13:31:07 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ancor;
	int			i;

	ancor = s;
	i = ft_strlen(s);
	s = (s + i - 1);
	while (s != ancor && c != *s)
		s--;
	if (c == *s)
		return ((char *)s);
	return (0);
}
