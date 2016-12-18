/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 09:50:52 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/18 18:15:09 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_coord	*tet;
	int			fd;
	int			i;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	tet = get_tet_list(fd);
	i = 0;
	while (i < 4)
	{
		ft_putnbr(tet[i].x);
		ft_putstr("; ");
		ft_putnbr(tet[i].y);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
