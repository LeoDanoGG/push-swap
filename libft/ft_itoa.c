/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:10:09 by legomez           #+#    #+#             */
/*   Updated: 2026/10/05 15:19:15 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int control */
static int	ft_count(long n1)
{
	size_t	num;

	num = 0;
	if (n1 != 0)
	{
		if (n1 < 0)
			n1 = -n1;
		while (n1 > 0)
		{
			n1 /= 10;
			num++;
		}
		return (num);
	}
	else
		return (1);
	return (num);
}

char	*ft_itoa(int n)
{
	char	*c;
	size_t	num;
	int		neg;
	long	n1;

	neg = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		neg++;
	}
	num = ft_count((long) n);
	c = (char *) ft_calloc((num + neg + 1), sizeof(char));
	if (!c)
		return (NULL);
	if (neg)
		c[0] = '-';
	c[num + neg] = '\0';
	while (num-- > 0)
	{
		c[num + neg] = (n1 % 10 + '0');
		n1 /= 10;
	}
	return (c);
}
