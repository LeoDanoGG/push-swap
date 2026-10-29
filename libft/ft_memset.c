/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:15:12 by legomez           #+#    #+#             */
/*   Updated: 2026/10/01 09:36:51 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* mem control */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	b = s;
	while (n-- > 0)
		b[n] = (unsigned char) c;
	return (s);
}
