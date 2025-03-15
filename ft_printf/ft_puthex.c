/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <aben-hzz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:16:00 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/01/04 16:11:36 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long nb, int cas, int *counter)
{
	char	*hex_base;

	if (cas == 1)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (nb >= 16)
		ft_puthex(nb / 16, cas, counter);
	ft_putchar(hex_base[nb % 16], counter);
}
