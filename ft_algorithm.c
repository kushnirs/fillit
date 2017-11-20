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

void	ft_bit_figure()
{
	int			i;
	int			j;
	t_square	*tmp;	

	tmp = NULL;
	tmp = g_figure;
	while (tmp)
	{
		i = -1;
		while (tmp->map[++i])
		{
			j = -1;
			while (tmp->map[i][++j])
				if (tmp->map[i][j] == '#')
					tmp->sqr = tmp->sqr | (1L << (i * 16 + j));
		}
		tmp = tmp->next;
	}
	unsigned long num = g_figure->sqr;
	int k;
    for(k = 63; k >= 0; --k)
        printf("%d", num & (1L << k) ? 1 : 0);
}

void ft_algorithm(void)
{
	ft_bit_figure();
}
