/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:46:38 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/26 15:13:28 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_switch(t_square *tmp, unsigned short *map)
{
	*(unsigned long*)(map + tmp->y) ^= tmp->sqr >> tmp->x;
}

int		ft_tryfill(t_square *tmp, unsigned short *map)
{
	return (!(*(unsigned long*)(map + tmp->y) & (tmp->sqr >> tmp->x)));
}
