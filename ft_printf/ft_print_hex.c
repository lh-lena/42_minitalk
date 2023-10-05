/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:53:08 by ohladkov          #+#    #+#             */
/*   Updated: 2023/07/19 12:44:32 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexupp(long n, unsigned int base)
{
	int			count;
	const char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n >= base)
		count += print_hexupp(n / base, base);
	n = symbols[n % base];
	count += write(1, &n, 1);
	return (count);
}

int	print_unshex(unsigned long long n, unsigned int base)
{
	int			count;
	const char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n >= base)
		count += print_unshex(n / base, base);
	n = symbols[n % base];
	count += write(1, &n, 1);
	return (count);
}
