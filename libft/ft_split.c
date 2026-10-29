/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 11:01:11 by legomez           #+#    #+#             */
/*   Updated: 2026/10/05 15:24:09 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* str control */
static void	*free_matrix(char **matrix, int i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	return (NULL);
}

static int	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static void	*chunk(char **matrix, char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			j = i;
			while (str[i] && str[i] != c)
				i++;
			matrix[k] = ft_substr(str, j, i - j);
			if (!matrix[k])
				return (free_matrix(matrix, k));
			k++;
		}
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	words;

	words = count_words(s, c);
	matrix = ft_calloc((words + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!chunk(matrix, s, c))
	{
		free(matrix);
		return (NULL);
	}
	matrix[words] = NULL;
	return (matrix);
}
