/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:50:07 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/11/10 09:59:59 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	tmp;
	int			len;
	char		*res;

	tmp = n;
	len = digit_size(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (tmp == 0)
		res[0] = '0';
	if (tmp < 0)
	{
		res[0] = '-';
		tmp = -tmp;
	}
	while (tmp)
	{
		res[--len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	return (res);
}
