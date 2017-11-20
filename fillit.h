/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:08:58 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/20 03:03:02 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// # include <unistd.h>
# include <fcntl.h>
// # include <string.h>
// # include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct	s_square
{
	int				word;
	char			**map;
	unsigned long	sqr;
	struct s_square	*next;
}				t_square;

t_square	*ft_lstnev();

#endif
