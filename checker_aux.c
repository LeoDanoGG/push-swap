/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:36:52 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/24 10:44:00 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Auxiliar to checker to accept spaces before and after operation strings
char	*checker_parse(char *op)
{
	char		*c;
	static char	parsed[5];
	int			n;

	if (!op)
		return (NULL);
	n = 0;
	c = op;
	while (*c == ' ')
		c++;
	while (ft_isalpha((char)*c) && n < 3)
	{
		parsed[n] = *c;
		c++;
		n++;
	}
	while (*c == ' ')
		c++;
	if (*c == '\n')
		parsed[n++] = '\n';
	parsed[n] = '\0';
	return (parsed);
}
