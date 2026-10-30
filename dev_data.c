/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legomez <legomez@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:56:40 by legomez           #+#    #+#             */
/*   Updated: 2026/10/30 19:22:02 by legomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dev.h"

#define LEN(x) ((int)(sizeof(x) / sizeof(int)))

static const int	g_one[] = {42};
static const int	g_sorted[] = {1, 2, 3, 4, 5};
static const int	g_five[] = {3, 5, 1, 4, 2};
static const int	g_ten[] = {7, 2, 9, 1, 5, 10, 3, 8, 6, 4};
static const int	g_neg[] = {-3, 5, 0, -10, 8, 2};

static const t_preset	g_presets[] = {
	{"one", g_one, LEN(g_one)},
	{"sorted", g_sorted, LEN(g_sorted)},
	{"five", g_five, LEN(g_five)},
	{"ten", g_ten, LEN(g_ten)},
	{"neg", g_neg, LEN(g_neg)}
};

void	list_presets(void)
{
	int	i;

	i = 0;
	while (g_presets[i].name)
	{
		ft_putchar_fd(' ', 1);
		ft_putstr_fd((char *)g_presets[i].name, 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

static int	*copy_ints(const int *src, int len)
{
	int	*dst;
	int	i;

	dst = malloc(sizeof(int) * len);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

static int	*gen_random(int n, int seed)
{
	int	*d;
	int	i;
	int	j;
	int	tmp;

	if (n < 1)
		return (NULL);
	d = malloc(sizeof(int) * n);
	if (!d)
		return (NULL);
	srand(seed);
	i = -1;
	while (++i < n)
		d[i] = i;
	i = n - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		tmp = d[i];
		d[i] = d[j];
		d[j] = tmp;
		i--;
	}
	return (d);
}

static int	*find_preset(const char *name, int *len)
{
	int	i;

	i = 0;
	while (g_presets[i].name)
	{
		if (!ft_strncmp(name, g_presets[i].name, ft_strlen(name) + 1))
		{
			*len = g_presets[i].len;
			return (copy_ints(g_presets[i].data, *len));
		}
		i++;
	}
	return (NULL);
}

int	*get_data(int argc, char **argv, int *len)
{
	int	*d;
	int	i;

	*len = 0;
	if (argc < 2)
		return (NULL);
	if (!ft_strncmp(argv[1], "rand", 5))
	{
		*len = 100;
		if (argc > 2)
			*len = ft_atoi(argv[2]);
		i = 42;
		if (argc > 3)
			i = ft_atoi(argv[3]);
		return (gen_random(*len, i));
	}
	d = find_preset(argv[1], len);
	if (d || (!ft_isdigit(argv[1][0]) && argv[1][0] != '-'))
		return (d);
	*len = argc - 1;
	d = malloc(sizeof(int) * *len);
	i = -1;
	while (d && ++i < *len)
		d[i] = ft_atoi(argv[i + 1]);
	return (d);
}
