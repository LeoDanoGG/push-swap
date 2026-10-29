/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:54:41 by legomez           #+#    #+#             */
/*   Updated: 2026/09/28 09:57:12 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* mem control */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ds;
	const unsigned char	*sr;
	size_t				i;

	ds = (unsigned char *) dest;
	sr = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (ds > sr)
	{
		i = n;
		while (i-- > 0)
			ds[i] = sr[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
