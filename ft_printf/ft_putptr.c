/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:34:46 by aben-hzz          #+#    #+#             */
/*   Updated: 2025/01/05 10:34:49 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *counter)
{
	unsigned long	add;

	if (!ptr)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	add = (unsigned long)ptr;
	ft_putstr("0x", counter);
	ft_puthex(add, 0, counter);
}
