/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:33:05 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/29 07:30:34 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);
int		ft_onepercent(void);
size_t	ft_ptr(void *adress);
size_t	ft_putchar_fd(const char c, int fd);
size_t	ft_putchar(const char c);
size_t	ft_strlen(const char *s);
size_t	ft_putstr(const char *str);
size_t	ft_hex(unsigned int num, const char format);
size_t	ft_putnbr(const int n);
size_t	ft_putunbr(const unsigned int n);

#endif
