/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:43:22 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/20 10:26:56 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square	*ft_lstnev()
{
	t_square	*figure;

	if ((figure = (t_square*)malloc(sizeof(t_square))) == NULL)
		return (0);
	if ((figure->map = (char**)malloc(sizeof(char*) * 26)) == NULL)
		return (0);
	figure->next = NULL;
	return (figure);
}
