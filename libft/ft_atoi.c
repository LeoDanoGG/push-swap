/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:44:27 by legomez           #+#    #+#             */
/*   Updated: 2026/10/01 15:46:24 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int control */
int	ft_atoi(const char *src)
{
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	while (*src == ' ' || (*src >= 9 && *src <= 13))
		src++;
	if ((*src == '-' || *src == '+'))
	{
		if (src[1] == '-' || src[1] == '+')
			return (0);
		if (*src == '-')
			sign = -1;
		src++;
	}
	while (*src && ft_isdigit(*src))
	{
		n = (n * 10) + (*src - '0');
		src++;
	}
	return (n * sign);
}
