/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:45:29 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/19 14:01:11 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Simple error and free
int	error(t_stack *a, t_stack *b)
{
	ft_stack_clear(a);
	ft_stack_clear(b);
	ft_printferr("Error\n");
	return (-1);
}
