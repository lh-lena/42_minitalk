/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:48 by ohladkov          #+#    #+#             */
/*   Updated: 2023/07/19 12:36:12 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(*args, int));
	else if (specifier == 's')
		count += print_str(va_arg(*args, char *));
	else if (specifier == 'd')
		count += print_digit(va_arg(*args, int));
	else if (specifier == 'u')
		count += print_digit(va_arg(*args, unsigned int));
	else if (specifier == 'i')
		count += print_digit(va_arg(*args, int));
	else if (specifier == 'x')
		count += print_unshex(va_arg(*args, unsigned int), 16);
	else if (specifier == 'X')
		count += print_hexupp(va_arg(*args, unsigned int), 16);
	else if (specifier == 'p')
		count += print_ptr(va_arg(*args, void *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += printf_format(*format, &args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end (args);
	return (count);
}
