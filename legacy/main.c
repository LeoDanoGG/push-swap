/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:00:17 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 19:23:53 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

void	show(t_arr *a, t_arr *b)
{
	if (a->size <= 30)
		print_stacks(a, b);
	else
		ft_printf("(stack grande, no se imprime)\n");
}

static void	free_arr(t_arr *s)
{
	if (!s)
		return ;
	free(s->arr);
	free(s);
}

int	main(int argc, char **argv)
{
	t_arr	*a;
	t_arr	*b;
	int		*data;
	int		len;

	if (argc == 1)
		return (1);
	data = get_data(argc, argv, &len);
	if (!data)
		return (list_presets(), 1);
	a = new_arr(len);
	b = new_arr(len);
	if (!a || !b)
		return (1);
	while (a->count < len)
		add_back(a, data[a->count]);
	free(data);
	dev_sort(a, b);
	show(a, b);
	if (is_sorted(a) && !b->count)
		ft_printf("OK\n", 1);
	else
		ft_printf("KO\n", 1);
	return (free_arr(a), free_arr(b), 0);
}
