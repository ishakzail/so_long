/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:04:14 by izail             #+#    #+#             */
/*   Updated: 2022/04/05 14:04:15 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (c == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (c == 'x')
		len += ft_putlhex(va_arg(ap, unsigned long));
	else if (c == 'X')
		len += ft_putuhex(va_arg(ap, unsigned int));
	else if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putlhex(va_arg(ap, unsigned long));
	}
	else if (c == 'u')
		len += ft_putdmc(va_arg(ap, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	len;

	len = 0;
	va_list(ap);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_format(ap, *str);
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (len);
}