// #include "push_swap.h"

// void double_swap(t_stack *a, t_stack *b)
// {
// 	swap(a);
// 	swap(b);
// }

// void double_rotate(t_stack *a, t_stack *b)
// {
// 	rotate(a);
// 	rotate(b);
// }

// void double_reverse(t_stack *a, t_stack *b)
// {
// 	reverse_rotate(a);
// 	reverse_rotate(b);
// }

// void perform_operation(char *op, t_stack *a, t_stack *b)
// {
// 	if (ft_strncmp(op, "pa\n", 3) == 0)
// 		push(b, a);
// 	else if (ft_strncmp(op, "pb\n", 3) == 0)
// 		push(a, b);
// 	else if (ft_strncmp(op, "sa\n", 3) == 0)
// 		swap(a);
// 	else if (ft_strncmp(op, "sb\n", 3) == 0)
// 		swap(b);
// 	else if (ft_strncmp(op, "ss\n", 3) == 0)
// 		double_swap(a, b);
// 	else if (ft_strncmp(op, "ra\n", 3) == 0)
// 		rotate(a);
// 	else if (ft_strncmp(op, "rb\n", 3) == 0)
// 		rotate(b);
// 	else if (ft_strncmp(op, "rr\n", 3) == 0)
// 		double_rotate(a, b);
// 	else if (ft_strncmp(op, "rra\n", 3) == 0)
// 		reverse_rotate(a);
// 	else if (ft_strncmp(op, "rrb\n", 3) == 0)
// 		reverse_rotate(b);
// 	else if (ft_strncmp(op, "rrr\n", 3) == 0)
// 		double_reverse(a, b);
// }

// int main(int argc, char **argv)
// {
// 	char *op = ft_calloc(5, 1);
// 	ssize_t bytes = 0;
// 	t_stack *a = valid_input(argc -1, argv +1);
// 	t_stack *b = ft_calloc(1, sizeof(t_stack));
// 	if (!a || !b)
// 	{
// 		ft_stack_clear(a);
// 		ft_stack_clear(b);
// 		free(a);
// 		free(b);
// 	}
	
// 	while ((bytes = read(0, op, 4)) > 1) // Change for gnl
// 	{
// 		op[bytes] = '\0';
// 		perform_operation(op, a, b);
// 		ft_printferr("Error\n");
// 	}

// 	if (compute_disorder(a) == 0 && b->size == 0)
// 		ft_printf("OK\n");
// 	else
// 		ft_printf("KO\n");
// }
