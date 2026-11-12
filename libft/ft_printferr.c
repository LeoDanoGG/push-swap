/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printferr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:53:59 by legomez           #+#    #+#             */
/*   Updated: 2026/11/10 17:11:53 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printferr.h"

/* Prints return char */
int	err_print_chr(const char c)
{
	return (write(2, &c, 1));
}

/* Prints return string */
int	err_print_str(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += err_print_chr(*str++);
	return (count);
}

/* Validates format */
int	valid_format(const int c, const char *s)
{
	while (*s)
	{
		if (*s == (char) c)
			return (1);
		s++;
	}
	return (0);
}

/* Controls the format */
static int	ft_parser(char const *specifier, va_list arg)
{
	if (*specifier == '%')
		return (err_print_chr('%'));
	else if (*specifier == 'c')
		return (err_print_chr(va_arg(arg, int)));
	else if (*specifier == 's')
		return (err_print_str(va_arg(arg, char *)));
	else if (*specifier == 'd' || *specifier == 'i')
		return (err_print_nbr(va_arg(arg, int)));
	else if (*specifier == 'p')
		return (err_print_ptr(va_arg(arg, unsigned long long), HEX_LOW, 1));
	else if (*specifier == 'u')
		return (err_print_unsigned(va_arg(arg, unsigned int)));
	else if (*specifier == 'x')
		return (err_print_hex(va_arg(arg, long), HEX_LOW));
	else if (*specifier == 'X')
		return (err_print_hex(va_arg(arg, long), HEX_UP));
	return (0);
}

/* Check *format and args */
int	ft_printferr(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && valid_format(format[1], VALID_FORMAT))
		{
			format++;
			count += ft_parser(format, args);
		}
		else if (*format == '%' && !valid_format(format[1], VALID_FORMAT))
			count += err_print_chr(*format);
		else if (*format == '%' && !format[1])
			return (0);
		else
			count += err_print_chr(*format);
		format++;
	}
	va_end(args);
	return (count);
}
