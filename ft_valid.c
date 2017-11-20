/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:47:20 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/20 14:47:22 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_valid_symb(int fd, char *str)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
	i = 0;
	while (fd--)
	{
		str[i] == '#' ? k++ : k;
		if (i == 20 && k != 4)
			return (0);
		else if (i == 20)
		{
			str = &str[i + 1];
			i = 0;
			k = 0;
			continue;
		}
		i++;
	}
	return (1);
}

int			ft_valid_lbr(int fd, char *str)
{
	int	i;
	int	k;

	i = 4;
	k = 0;
	while (i < fd)
	{
		if (str[i] != '\n')
			return (0);
		i = i + 5;
		if (++k == 4)
		{
			i = i + 1;
			k = 0;
		}
	}
	i = 20;
	while (i < fd)
	{
		if (str[i] != '\n')
			return (0);
		i = i + 21;
	}
	return (1);
}

static int	ft_valid_figure_cont(int i, int j, int val, t_square *tmp)
{
	if (i - 1 >= 0 && tmp->map[i - 1][j] == '#')
		val++;
	if (i + 1 <= 3 && tmp->map[i + 1][j] == '#')
		val++;
	if (j + 1 <= 3 && tmp->map[i][j + 1] == '#')
		val++;
	if (j - 1 >= 0 && tmp->map[i][j - 1] == '#')
		val++;
	return (val);
}

int			ft_valid_figure(void)
{
	int			i;
	int			j;
	int			val;
	t_square	*tmp;

	tmp = g_figure;
	while (tmp->next)
	{
		val = 0;
		i = -1;
		while (tmp->map[++i])
		{
			j = -1;
			while (tmp->map[i][++j])
				if (tmp->map[i][j] == '#')
					val = ft_valid_figure_cont(i, j, val, tmp);
		}
		if (val != 6 && val != 8)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
