/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:30:10 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/26 16:19:14 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_filling(t_square *tmp, int min_sqr, unsigned short *map)
{
	if (!tmp)
		return (1);
	tmp->y = 0;
	tmp->x = 0;
	while ((tmp->y + tmp->h) <= min_sqr)
	{
		while ((tmp->x + tmp->w) <= min_sqr)
		{
			if (ft_tryfill(tmp, map))
			{
				ft_switch(tmp, map);
				if (ft_filling(tmp->next, min_sqr, map))
					return (1);
				ft_switch(tmp, map);
			}
			tmp->x++;
		}
		tmp->y++;
		tmp->x = 0;
	}
	tmp->y = 0;
	tmp->x = 0;
	return (0);
}

static void	ft_shift_size(t_square *tmp)
{
	unsigned long	mask;

	mask = 0;
	mask = ~(~mask << 16);
	while (!(tmp->sqr & mask))
		tmp->sqr = tmp->sqr >> 16;
	mask = 0;
	mask = (mask | 1L << 15) | (mask | 1L << 31) |
	(mask | 1L << 47) | (mask | 1L << 63);
	while (!(tmp->sqr & mask))
		tmp->sqr = tmp->sqr << 1;
	while ((tmp->sqr & (mask >> tmp->w)))
		tmp->w++;
	tmp->w == 0 ? tmp->w = 1 : 0;
	while (tmp->h < 4 && tmp->sqr >> (16 * tmp->h))
		tmp->h++;
}

static void	ft_bit_figure(void)
{
	int				i;
	int				j;
	t_square		*tmp;

	tmp = NULL;
	tmp = g_figure;
	while (tmp->next)
	{
		i = -1;
		while (tmp->map[++i])
		{
			j = -1;
			while (tmp->map[i][++j])
				if (tmp->map[i][j] == '#')
					tmp->sqr |= (1L << (63 - ((3 - i) * 16 + j)));
		}
		i = -1;
		while (++i < 4)
			free(tmp->map[i]);
		ft_shift_size(tmp);
		tmp = tmp->next;
	}
}

void		ft_algorithm(int fd)
{
	int				min_sqr;
	unsigned short	*map;

	min_sqr = 2;
	while (min_sqr * min_sqr < ((fd + 1) / 21 * 4))
		min_sqr++;
	map = (unsigned short *)ft_memalloc(16 * 16);
	ft_bit_figure();
	while (!ft_filling(g_figure, min_sqr, map))
	{
		ft_bzero(map, 16 * 16);
		min_sqr++;
	}
	ft_output(min_sqr);
}
