/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circular_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:56:57 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/03 09:58:56 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create new array with size for numbers
t_arr	*new_arr(int size)
{
	t_arr	*arr;

	if (size < 1)
		return (NULL);
	arr = ft_calloc(1, sizeof(t_arr));
	if (!arr)
		return (NULL);
	arr -> arr = ft_calloc (size, sizeof(int));
	if (!arr->arr)
	{
		free(arr);
		return (NULL);
	}
	arr -> size = size;
	arr -> start = 0;
	arr -> end = 0;
	arr -> count = 0;
	return (arr);
}

// Return the number at index. arr_indx(arr, 2) == arr[2]
int	arr_indx(t_arr *arr, int i)
{
	if (arr -> count < i || arr -> size < i || !arr)
		return (0);
	return (arr->arr[(arr->start + i) % arr->size]);
}
