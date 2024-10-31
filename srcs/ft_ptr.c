/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:49:32 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/29 06:17:18 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	printadress(unsigned long n)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += printadress(n / 16);
	if ((n % 16) < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16) - 10 + 'a');
	return (count);
}

size_t	ft_ptr(void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + printadress((unsigned long)adress));
}
