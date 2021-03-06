/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:15:12 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/26 16:19:28 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square	*g_figure = NULL;

static void	ft_letter(void)
{
	char		i;
	t_square	*tmp;

	i = 65;
	tmp = g_figure;
	while (tmp->next)
	{
		tmp->letter = i++;
		tmp = tmp->next;
	}
}

static int	ft_figure(int fd, char *str)
{
	int			i;
	char		**fig;
	t_square	*tmp;

	g_figure = ft_lstnev();
	fig = ft_strsplit(str, '\n');
	tmp = g_figure;
	fd = (fd + 1) / 21 + 1;
	while (--fd)
	{
		i = -1;
		while (++i < 4)
		{
			if ((tmp->map[i] = (char*)ft_memalloc(sizeof(char) * 4)) == NULL)
				return (0);
			tmp->map[i] = fig[i];
		}
		tmp->next = ft_lstnev();
		tmp = tmp->next;
		fig = fig + 4;
	}
	free(str);
	ft_letter();
	return (1);
}

int			main(int argc, char **argv)
{
	int		disp;
	int		fd;
	char	*str;

	if (argc != 2)
		return (write(1, "error\n", 6));
	if (!(str = (char *)malloc(546)))
		return (0);
	disp = open(argv[1], O_RDONLY);
	fd = read(disp, str, 546);
	str[fd] = 0;
	close(fd);
	if (fd > 545 || (fd + 1) % 21 || fd == -1)
		return (write(1, "error\n", 6));
	if (ft_valid_lbr(fd, str) == 0 || ft_valid_symb(fd, str) == 0)
		return (write(1, "error\n", 6));
	if (ft_figure(fd, str) == 0 || ft_valid_figure() == 0)
		return (write(1, "error\n", 6));
	ft_algorithm(fd);
	return (0);
}
