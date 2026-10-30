/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circular_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:56:57 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/10/30 10:41:04 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Create new array with size for numbers
t_arr	*new_arr(int size)
{
	t_arr	*arr;

	arr = ft_calloc(1, sizeof(t_arr));
	if (!arr)
		return (NULL);
	arr -> size = size;
	arr -> arr = ft_calloc (size, sizeof(int));
	arr -> start = 0;
	arr -> end = 0;
	arr -> count = 0;
	return (arr);
}

//Return the number at index. arr_indx(arr, 2) == arr[2]
int	arr_indx(t_arr *arr, int i)
{
	int	val;

	if (arr -> count < i || arr -> size < i || !arr)
		return (0);
	val = arr->arr[(arr->start + i) % arr->size];
	return (val);
}
