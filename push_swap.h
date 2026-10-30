/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:09:53 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 11:07:04 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* Circular Array */
typedef struct s_arr // Circular Array Struct
{
	int	*arr;	// Int array
	int	start;	// Index of the first int
	int	end;	// Index of the first empty space on the array
	int	size;	// Max Size of the array
	int	count;	// Count of ints in the array
}	t_arr;

void	add_front(t_arr *arr, int n);
void	add_back(t_arr *arr, int n);
int		del_front(t_arr *arr);
int		del_back(t_arr *arr);
t_arr	*new_arr(int size);
int		arr_indx(t_arr *arr, int i);

/* Basic Operations */
void	swap(t_arr *arr);
void	push(t_arr *src, t_arr *dest);
void	rotate(t_arr *arr);
void	reverse_rotate(t_arr *arr);

#endif
