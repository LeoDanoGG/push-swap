/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 18:14:00 by legomez           #+#    #+#             */
/*   Updated: 2026/10/04 20:22:44 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* str control */
static size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	trim_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	if (i == 0)
		return (0);
	while (i > 0 && ft_strchr(set, s1[i - 1]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*c;
	size_t	st;
	size_t	nd;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	st = trim_start(s1, set);
	nd = trim_end(s1, set);
	if (st >= nd)
		return ((void *) ft_calloc(1, sizeof(char)));
	c = (char *) ft_calloc((nd - st + 1), sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (st < nd)
		c[i++] = s1[st++];
	return (c);
}
