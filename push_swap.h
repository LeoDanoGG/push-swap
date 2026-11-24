/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:09:53 by legomez           #+#    #+#             */
/*   Updated: 2026/11/19 09:27:38 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

/* Linked List */
typedef struct s_node
{
	int				val;
	int				norm_val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	size_t	ops[7];
	t_node	*head;
}	t_stack;

t_node	*ft_nodenew(int val, int norm);
void	ft_node_addback(t_stack *stack, t_node *new);
void	ft_node_addfront(t_stack *stack, t_node *new);
t_node	*ft_node_last(t_stack *stack);
size_t	ft_stack_size(t_node *head);
void	ft_stack_clear(t_stack *stack);
void	ft_node_delone(t_node *node);
void	ft_stack_normailze(t_stack *stack);
t_node	*ft_node_at(t_stack *stack, int idx);

/* Basic operations */
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
int		compute_disorder(t_stack *stack);

/* Basic operations wrapper*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Parse input */
t_stack	*valid_input(int argc, char **argv);

/* Runner */
int		run_mode(int mode, t_stack *a, t_stack *b);

/* Error */
int		error(t_stack *a, t_stack *b);
void	bench(int mode, int disorder, t_stack *a, t_stack *b);

/* Sort for a small amount of numbers */
void	small_sort(t_stack *a, t_stack *b);

/* Algorithms */
void	ft_radix_lsd(t_stack *a, t_stack *b);
void	ft_turk_sort(t_stack *a, t_stack *b);
void	ft_range_sort(t_stack *a, t_stack *b);

/* Cost for a and b */
typedef struct s_cost
{
	int	ca;
	int	cb;
}	t_cost;

/* Turk and range sort utils */
int		signed_cost(int size, int idx);
int		find_max_idx(t_stack *s);
int		find_insert_idx(t_stack *b, int val);
t_cost	find_cheapest(t_stack *a, t_stack *b);
void	bring_to_top(t_stack *b, int idx);
void	rotate_both(t_stack *a, t_stack *b, t_cost *c);
void	rotate_a(t_stack *a, int ca);
void	rotate_b(t_stack *b, int cb);

/* Parser for checker (bonus) */
char	*checker_parse(char *op);

#endif
