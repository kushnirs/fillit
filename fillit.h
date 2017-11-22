/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:08:58 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/20 10:26:58 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct	s_square
{
	int				letter;
	char			**map;
	char			x;
	char			y;
	char			h;
	char			w;
	unsigned long	sqr;
	struct s_square	*next;
}				t_square;

extern t_square	*g_figure;
t_square		*ft_lstnev();
void			ft_algorithm(void);
int				ft_valid_symb(int fd, char *str);
int				ft_valid_lbr(int fd, char *str);
int				ft_valid_figure(void);
void			ft_output(int size);

#endif
