/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circular_array_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:56:27 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/10/30 10:10:40 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Add number to the front of the array
void	add_front(t_arr *arr, int n)
{
	if (arr -> count == arr -> size || !arr)
		return ;
	arr->start = (arr->start -1 + arr->size) % arr->size;
	arr->arr[arr->start] = n;
	arr->count ++;
}

//Add number to the back of the array
void	add_back(t_arr *arr, int n)
{
	if (arr -> count == arr -> size || !arr)
		return ;
	arr->arr[arr->end] = n;
	arr->end = (arr-> end +1) % arr->size;
	arr->count ++;
}

//Remove number from the front of the array
int	del_front(t_arr *arr)
{
	int	val;

	if (arr->count == 0 || !arr)
		return (0);
	val = arr->arr[arr->start];
	arr->arr[arr->start] = 0;
	arr->start = (arr->start +1) % arr->size;
	arr->count --;
	return (val);
}

//Remove number from the back of the array
int	del_back(t_arr *arr)
{
	int	val;

	if (arr->count == 0 || !arr)
		return (0);
	arr->end = (arr->end -1 + arr->size) % arr->size;
	val = arr->arr[arr->end];
	arr->arr[arr->end] = 0;
	arr->count --;
	return (val);
}
