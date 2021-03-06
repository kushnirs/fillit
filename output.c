/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:43:40 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/26 16:19:49 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fill_sqr(char **square, t_square *figures)
{
	int		i;
	int		j;

	i = figures->y - 1;
	while (++i < (figures->y + figures->h))
	{
		j = figures->x - 1;
		while (++j < (figures->x + figures->w))
			figures->sqr & (1L << (16 * i + 15 - (j - figures->x))) ?
				square[i][j] = figures->letter : 0;
	}
}

void		ft_output(int size)
{
	int			i;
	int			j;
	t_square	*figures;
	char		**square;

	figures = g_figure;
	if (!(square = (char**)ft_memalloc(sizeof(char*) * size)))
		exit(0);
	i = -1;
	while (++i < size)
		if (!(square[i] = (char*)ft_memalloc(sizeof(char) * size)))
			exit(0);
	i = -1;
	while (++i < size)
		ft_memset(square[i], '.', size);
	while (figures->next)
	{
		ft_fill_sqr(square, figures);
		figures = figures->next;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(square[i][j]);
		ft_putchar('\n');
	}
}
