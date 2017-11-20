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

void	ft_bit_figure(t_square figure)
{
	int	i;
	int	j;

	while (figure)
	{
		i = 0;
		while (figure->map[i])
		{
			j = 0;
			while (figure->map[i][j])
				if (figure->map[i][j] == '#')
					figure->sqr = 1 << 63 - j++;
			i++;
		}
		figure = figure->next;
	}
	int num=8, i;
    for(i=sizeof(num)*8-1; i>=0; --i)
        printf("%d", num&(1<<i)?1:0);
}

void ft_algorithm(t_square figure)
{
	ft_bit_figure(figure);
}
