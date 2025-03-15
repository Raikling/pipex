/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:16:19 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/12/15 13:16:38 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *counter)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", counter);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', counter);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, counter);
	ft_putchar(((nbr % 10) + '0'), counter);
}
