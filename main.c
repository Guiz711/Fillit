/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:50:52 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/10 15:55:35 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void	print(t_sqr sqr)
{
	int y;

	y = 0;
	while (sqr.map[y])
		ft_putendl(sqr.map[y++]);
}

int		main(int argc, char **argv)
{
	t_list		*tet_list;
	int			fd;
	t_sqr		sqr;
	int i;
	int j;

	if (argc != 2)
	{
		ft_putendl("program takes one argument");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(tet_list = get_tet_list(fd)))
	{
		ft_putendl("Error");
		return (0);
	}
	sqr.map = (char**)ft_memalloc(sizeof(sqr.map) * 5);
	i = 0;
	while (i < 4)
	{
		sqr.map[i] = (char*)ft_memalloc(sizeof(*sqr.map) * 5);
		j = 0;
		while (j < 4)
			sqr.map[i][j++] = '.';
		i++;
	}
	sqr.map[i] = NULL;
	sqr.size  = 4;
	solve(tet_list, &sqr, 'A');
	print(sqr);
}
