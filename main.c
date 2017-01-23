/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:50:52 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/19 16:32:35 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void lst_del(t_list **tet_list)
{
	t_list	*lst;
	t_list	*lstnext;

	lst = *tet_list;
	while (lst)
	{
		lstnext = lst->next;
		lst->content = NULL;
		free(lst);
		lst = lstnext;
	}
	*tet_list = NULL;
}


void	print(t_sqr sqr)
{
	int y;

	y = 0;
	while (sqr.map[y])
		ft_putendl(sqr.map[y++]);
}

int		main(int argc, char **argv)
{
	t_list		**tet_list;
	int			fd;

	tet_list = NULL;
	if (argc != 2)
	{
	:	ft_putendl("program takes one argument");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (get_tet_list(fd, tet_list) != 1)
	{
		ft_putendl("error");
		return (0);
	}
	if (!find_square(*tet_list))
	{
		ft_putendl("Error");
		return (0);
		lst_del(tet_list);
	}
	lst_del(tet_list);
	return (0);
}
