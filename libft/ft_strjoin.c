/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:53:28 by legomez           #+#    #+#             */
/*   Updated: 2026/10/19 12:33:34 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* str control */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	l1;
	size_t	l2;
	size_t	i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	c = ft_calloc((l1 + l2 + 1), sizeof(char));
	if (!c)
		return (NULL);
	while (i < l1)
	{
		c[i] = s1[i];
		i++;
	}
	while (i < (l1 + l2))
	{
		c[i] = s2[i - l1];
		i++;
	}
	return (c);
}
