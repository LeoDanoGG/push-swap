/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_operations_wrapper3.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtomas-m <gtomas-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:28:55 by gtomas-m          #+#    #+#             */
/*   Updated: 2026/11/10 16:16:12 by gtomas-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	a->ops[6]++;
	print_str("rrr\n");
}
