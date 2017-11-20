/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 23:15:12 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/20 10:26:55 by skushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_valid_figure(t_square *figure)
{
	int			i;
	t_square	*tmp;

	i = 65;
	tmp = figure;
	while (tmp)
	{
		tmp->word = i;
		tmp = tmp->next;
	}	
	return (1);
}

static int	ft_figure(int fd, char *str)
{
	int			i;
	char		**fig;
	t_square	*figure;
	t_square	*tmp;

	figure = NULL;
	figure = ft_lstnev();
	fig = ft_strsplit(str, '\n');
	tmp = figure;
	fd = (fd + 1) / 21 + 1;
	while (--fd)
	{
		i = -1;
		while (++i < 4)
		{
			if ((tmp->map[i] = (char*)malloc(sizeof(char) * 4)) == NULL)
				return (0);
			tmp->map[i] = fig[i];
		}
		tmp->next = ft_lstnev();
		tmp = tmp->next;
		fig = fig + 4;
	}
	free (str);
	ft_algorithm(figure);
}

static int	ft_valid_symb(int fd, char *str)
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
			str = &str[i +  1];
			i = 0;
			k = 0;
			continue;
		}
		i++;
	}
	return (1);
}

static int	ft_valid_lbr(int fd, char *str)
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
	while(i < fd)
	{
		if (str[i] != '\n')
			return (0);
		i = i + 21;
	}
	if (ft_valid_symb(fd, str) == 0)
		return (0);
}

int			main(int argc, char **argv)
{
	int		disp;
	int		fd;
	char	*str;

	if (argc != 2)
		return (write(1, "error\n",6));
	if ((str = (char *)malloc(546)) == NULL)
		return (0);
	disp = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(write(1, "error\n",6));
	fd = read(disp, str, 546);
	str[fd] = 0;
	if (fd > 545)
		return(write(1, "error\n",6));
	if (ft_valid_lbr(fd, str) == 0)
		return(write(1, "error\n",6));
	if (ft_figure(fd, str) == 0)
		return(write(1, "error\n",6));
		if (ft_valid_figure(figure) == 0)
		return (0);
	//printf("yspeh\n");
	return (0);
}
