/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:43:16 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/03 09:59:29 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first to numbers of stack
void	swap(t_arr *arr)
{
	int	first_idx;
	int	second_idx;
	int	temp;

	first_idx = arr->start;
	second_idx = (arr->start +1) % arr->size;
	temp = arr -> arr[first_idx];
	arr -> arr[first_idx] = arr -> arr[second_idx];
	arr -> arr[second_idx] = temp;
}

// Remove the first number of src and add it into the top of dest
void	push(t_arr *src, t_arr *dest)
{
	int	val;

	val = del_front(src);
	add_front(dest, val);
}

// Move up all the numbers of arr making the first number last
void	rotate(t_arr *arr)
{
	int	val;

	val = del_front(arr);
	add_back(arr, val);
}

// Move down all the numbers of arr making the last number first
void	reverse_rotate(t_arr *arr)
{
	int	val;

	val = del_back(arr);
	add_front(arr, val);
}
