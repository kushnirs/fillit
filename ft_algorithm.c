/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 03:30:10 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/20 10:26:51 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void ft_shift_size(t_square *tmp)
{
	unsigned long 	mask;

	mask = 0;
	mask = ~(~mask >> 16);
	while (!(tmp->sqr & mask))
	  	tmp->sqr = tmp->sqr << 16;
	mask = 0; 
	mask = (mask | 1L << 15) | (mask | 1L << 31) | (mask | 1L << 47) | (mask | 1L << 63);
	while (!(tmp->sqr & mask))
		tmp->sqr = tmp->sqr << 1;
	while ((tmp->sqr & (mask >> tmp->w)))
		tmp->w++;
	tmp->w == 0 ? tmp->w = 1 : 0;
	while (tmp->h < 4 && tmp->sqr << (16 * tmp->h))
	 	tmp->h++;
}

static void	ft_bit_figure(void)
{
	int				i;
	int				j;
	unsigned long	mask;
	t_square		*tmp;	

	tmp = NULL;
	tmp = g_figure;
	while (tmp->next)
	{
		mask = 0;
		i = -1;
		while (tmp->map[++i])
		{
			j = -1;
			while (tmp->map[i][++j])
				if (tmp->map[i][j] == '#')
					tmp->sqr = tmp->sqr | (1L << (63 - (i * 16 + j)));
		}
		i = -1;
		while (++i < 4)
			free(tmp->map[i]);
		ft_shift_size(tmp);
		tmp = tmp->next;
	}
	// while (g_figure->next)
	// {
	// 	printf("%lu\n", g_figure->sqr);
	// 	printf("h = %d\n", g_figure->h);
	// 	printf("w = %d\n\n", g_figure->w);
	// 	unsigned long num = g_figure->sqr;
 //    	for(int k = 63; k >= 0; --k)
 //    	{
 //    	    printf("%d", num & (1L << k) ? 1 : 0);
 //    	    k % 16 == 0 ? printf("\n") : 0;
 //    	}
 //    	printf("\n");
 //    	g_figure = g_figure->next;
 //    }
}

void ft_algorithm(void)
{
	ft_bit_figure();
	g_figure->x = 3;
	g_figure->y = 0;
	g_figure->next->x = 6;
	g_figure->next->y = 0;
	g_figure->next->next->x = 3;
	g_figure->next->next->y = 5;
	g_figure->next->next->next->x = 6;
	g_figure->next->next->next->y = 5;
	ft_output(10);
}
