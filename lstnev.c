/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:43:22 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/26 15:13:17 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square	*ft_lstnev(void)
{
	t_square	*figure;

	if ((figure = (t_square*)ft_memalloc(sizeof(t_square))) == NULL)
		return (0);
	if ((figure->map = (char**)ft_memalloc(sizeof(char*) * 26)) == NULL)
		return (0);
	figure->h = 0;
	figure->w = 0;
	figure->next = NULL;
	return (figure);
}
