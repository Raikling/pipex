/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:16:51 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/12/15 13:17:45 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int ui, int *counter)
{
	if (ui >= 10)
		ft_putnbr_unsigned(ui / 10, counter);
	ft_putchar(((ui % 10) + '0'), counter);
}
