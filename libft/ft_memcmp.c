/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:58:32 by legomez           #+#    #+#             */
/*   Updated: 2026/10/01 12:39:16 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* mem control */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sr1;
	const unsigned char	*sr2;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	sr1 = (unsigned char *) s1;
	sr2 = (unsigned char *) s2;
	while (sr1[i] == sr2[i] && i < n - 1)
		i++;
	return (sr1[i] - sr2[i]);
}
