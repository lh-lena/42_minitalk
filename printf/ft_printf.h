/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:58:25 by ohladkov          #+#    #+#             */
/*   Updated: 2023/07/19 12:25:20 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n);
int	print_hexupp(long n, unsigned int base);
int	print_unshex(unsigned long long n, unsigned int base);
int	print_ptr(void *ptr);

#endif
