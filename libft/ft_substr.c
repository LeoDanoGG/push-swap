/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:04:04 by legomez           #+#    #+#             */
/*   Updated: 2026/10/06 11:30:51 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* str control */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (len > s_len - start)
		len = s_len - start;
	c = (char *) ft_calloc((len + 1), sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		c[i] = s[start + i];
		i++;
	}
	return (c);
}
