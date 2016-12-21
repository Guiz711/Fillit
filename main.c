/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:50:52 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/19 12:59:54 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_list		*tet_list;
	int			fd;
	int			i;

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
	while(tet_list)
	{
		i = 0;
		while (i < 4)
		{
			ft_putnbr(((t_coord*)tet_list->content)[i].x);
			ft_putstr("; ");
			ft_putnbr(((t_coord*)tet_list->content)[i].y);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		tet_list = tet_list->next;
	}
	return (0);
}
