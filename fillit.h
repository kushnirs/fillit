/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:08:58 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/26 14:16:20 by skushnir         ###   ########.fr       */
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
void			ft_algorithm(int fd);
int				ft_valid_symb(int fd, char *str);
int				ft_valid_lbr(int fd, char *str);
int				ft_valid_figure(void);
void			ft_output(int size);
int				ft_tryfill(t_square *tmp, unsigned short *map);
void			ft_switch(t_square *tmp, unsigned short *map);

#endif
