/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:09:53 by legomez           #+#    #+#             */
/*   Updated: 2026/11/03 15:44:05 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/*Linked List*/

typedef struct s_node
{
	int				val;
	int				norm_val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	unsigned int	size;
	t_node			*head;
}	t_stack;

t_node			*ft_nodenew(int val, int norm);
void			ft_node_addback(t_stack *stack, t_node *new);
void			ft_node_addfront(t_stack *stack, t_node *new);
t_node			*ft_node_last(t_stack *stack);
unsigned int	ft_stack_size(t_node *head);
void			ft_stack_clear(t_stack *stack);
void			ft_node_delone(t_node *node);
void			ft_stack_normailze(t_stack *stack);
t_node			*ft_node_at(t_stack *stack, int idx);

/* Prints the stack values*/
void			show_stack(t_stack *stack, char name);

/* Basic Operations */
void			swap(t_stack *stack);
void			push(t_stack *src, t_stack *dest);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
int				compute_disorder(t_stack *stack);

/*Parse input*/
t_stack			*valid_input(int argc, char **argv);

/*Algorithms*/
void			ft_radix_lsd(t_stack *a, t_stack *b);
void			ft_bubble_sort(t_stack *stack);
#endif
