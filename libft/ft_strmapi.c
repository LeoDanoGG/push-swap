/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 15:32:49 by legomez           #+#    #+#             */
/*   Updated: 2026/10/19 12:33:47 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* str control */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	size_t	i;

	if (!s || !f)
		return (NULL);
	c = ft_strdup(s);
	if (!c)
		return (NULL);
	i = 0;
	while (c[i])
	{
		c[i] = f(i, c[i]);
		i++;
	}
	return (c);
}
