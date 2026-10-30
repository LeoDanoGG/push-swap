/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:44 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 12:56:45 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

//Aquí va tu algoritmo de ordenación. Ejemplo mínimo para 2 elementos.
void	dev_sort(t_arr *a, t_arr *b)
{
	(void)b;
	if (a->count == 2 && arr_indx(a, 0) > arr_indx(a, 1))
		swap(a);
}
