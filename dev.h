/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:50 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 12:56:51 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEV_H
# define DEV_H

# include "push_swap.h"

typedef struct s_preset
{
	const char	*name;
	const int	*data;
	int			len;
}	t_preset;

/* dev_data.c */
int		*get_data(int argc, char **argv, int *len);
void	list_presets(void);

/* dev_utils.c */
void	print_stacks(t_arr *a, t_arr *b);
int		is_sorted(t_arr *a);
int		exec_op(const char *op, t_arr *a, t_arr *b);
int		read_line(char *buf, int max);

/* dev_sort.c */
void	dev_sort(t_arr *a, t_arr *b);

#endif
