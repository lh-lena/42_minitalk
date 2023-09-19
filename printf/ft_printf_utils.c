/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:45:44 by ohladkov          #+#    #+#             */
/*   Updated: 2023/07/19 12:42:42 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int		count;
	char	*s;

	if (!str)
		s = "(null)";
	else
		s = str;
	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	print_digit(long n)
{
	int			count;
	const char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		count += write (1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		count += print_digit(n / 10);
	n = symbols[n % 10];
	count += write(1, &n, 1);
	return (count);
}
