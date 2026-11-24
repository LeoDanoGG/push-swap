/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:49:55 by legomez           #+#    #+#             */
/*   Updated: 2026/11/18 15:47:29 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*take_bytes(int fd)
{
	int		bytes;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*build_line(char *stack)
{
	char	*ptr;
	size_t	len;

	ptr = ft_strchr(stack, '\n');
	if (ptr)
		len = (ptr - stack) + 1;
	else
		len = ft_strlen(stack);
	return (ft_substr(stack, 0, len));
}

char	*fill_stack(int fd, char *stack)
{
	char	*buff;
	char	*tmp;

	while (!ft_strchr(stack, '\n'))
	{
		buff = take_bytes(fd);
		if (!buff)
			break ;
		tmp = ft_strjoin(stack, buff);
		free(stack);
		free(buff);
		stack = tmp;
		if (!stack)
			return (NULL);
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	char	*stack;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = ft_calloc(1, sizeof(char *));
	if (!stack)
		return (NULL);
	stack = fill_stack(fd, stack);
	if (!stack || !stack[0])
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	line = build_line(stack);
	free(stack);
	return (line);
}
