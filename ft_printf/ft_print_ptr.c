/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:30:15 by ohladkov          #+#    #+#             */
/*   Updated: 2023/07/19 12:32:21 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	unsigned long long	address;
	int					count;

	count = 0;
	if (ptr == NULL)
		return (count += write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	address = (unsigned long long)ptr;
	count += print_unshex(address, 16);
	return (count);
}
