/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:37:12 by legomez           #+#    #+#             */
/*   Updated: 2026/10/01 12:18:14 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* mem control */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*chr;

	chr = (unsigned char *) s;
	while (n > 0)
	{
		if (*chr == (unsigned char) c)
			return ((void *) chr);
		chr++;
		n--;
	}
	return (NULL);
}
