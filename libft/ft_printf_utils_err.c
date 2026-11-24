/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_err.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:35:14 by legomez           #+#    #+#             */
/*   Updated: 2026/11/10 17:35:23 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printferr.h"

int	err_print_ptr(const unsigned long long ptr, char *hex, int start)
{
	int	count;

	count = 0;
	if (!ptr && start)
		return (count = err_print_str("(nil)"));
	if (start)
		count += err_print_str("0x");
	if (ptr >= 16)
	{
		count += err_print_ptr(ptr / 16, hex, 0);
		count += err_print_ptr(ptr % 16, hex, 0);
	}
	else
		count += err_print_chr(hex[ptr]);
	return (count);
}

int	err_print_nbr(const int n)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += err_print_chr('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
		count += err_print_nbr(nbr / 10);
	count += err_print_chr((nbr % 10) + '0');
	return (count);
}

int	err_print_unsigned(const unsigned int n)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = n;
	if (nbr > 9)
		count += err_print_unsigned(nbr / 10);
	count += err_print_chr((nbr % 10) + '0');
	return (count);
}

int	err_print_hex(const unsigned int n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += err_print_hex(n / 16, hex);
		count += err_print_hex(n % 16, hex);
	}
	else
		count += err_print_chr(hex[n]);
	return (count);
}
