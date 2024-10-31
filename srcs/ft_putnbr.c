/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:43:10 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/29 02:44:29 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	print_nb(long nb)
{
	size_t	count;

	count = 0;
	if (nb >= 10)
		count += print_nb(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

size_t	ft_putnbr(const int n)
{
	long	nb;
	size_t	count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	count += print_nb(nb);
	return (count);
}
