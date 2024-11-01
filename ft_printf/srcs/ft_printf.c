/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:07:30 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/31 04:40:30 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_handle_unknown_format(char format)
{
	int	print_length;

	print_length = ft_putchar('%');
	print_length += ft_putchar(format);
	return (print_length);
}

static int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_onepercent();
	else
		return (-1);
	return (print_length);
}

static int	ft_process_format(va_list args, const char *str, int *i)
{
	int	len;

	len = ft_formats(args, str[*i + 1]);
	if (len == -1)
		len = ft_handle_unknown_format(str[*i + 1]);
	(*i)++;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	if (!str || (str[0] == '%' && str[1] == 32))
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			print_length += ft_process_format(args, str, &i);
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
