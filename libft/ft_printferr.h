/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printferr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:43:49 by legomez           #+#    #+#             */
/*   Updated: 2026/11/10 17:09:55 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFERR_H
# define FT_PRINTFERR_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define VALID_FORMAT "cspdiuxX%"
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

/* Validate x format */
int		valid_format(const int c, const char *s);

/* Formats parser */
int		err_print_chr(const char c);
int		err_print_str(const char *str);
int		err_print_nbr(const int n);
int		err_print_unsigned(const unsigned int n);
int		err_print_ptr(const unsigned long long ptr, char *hex, int start);
int		err_print_hex(const unsigned int n, char *hex);

/* printf func */
int		ft_printferr(char const *format, ...);

#endif
