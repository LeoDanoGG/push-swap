/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:21:03 by legomez           #+#    #+#             */
/*   Updated: 2026/10/01 10:18:54 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* mem control */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	if (!dest && !src)
		return (NULL);
	ds = (unsigned char *) dest;
	sr = (unsigned char *) src;
	while (n > 0)
	{
		*ds = *sr;
		ds++;
		sr++;
		n--;
	}
	return (dest);
}
