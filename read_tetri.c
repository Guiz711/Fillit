/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:30:40 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/18 18:20:31 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdio.h>

char		**read_tet(int fd)
{
	char	**tet;
	int		line_cnt;
	int		flg;

	if (!(tet = (char**)malloc(sizeof(*tet) * 5)))
		return (NULL);
	line_cnt  = 0;
	while ((flg = get_next_line(fd, &tet[line_cnt])) > 0
			&& line_cnt < 4 && tet[line_cnt][0])
		line_cnt++;
	tet[line_cnt] = NULL;
	if (flg == -1 || line_cnt != 4)
	{
		line_cnt = 0;
		while (tet[line_cnt++])
			free(tet[line_cnt]);
		free(tet);
		return (NULL);
	}
	return (tet);
}

t_coord		start_coord(char **tet)
{
	t_coord init_coord;
	int		i;
	int		j;

	init_coord.x = 3;
	init_coord.y = 3;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[i][j] == '#')
			{
				if (j < init_coord.x)
					init_coord.x = j;
				if (i < init_coord.y)
					init_coord.y = i;
			}
			j++;
		}
		i++;
	}
	return (init_coord);
}

t_coord		*tetri_coord(char **tet)
{
	t_coord		*tet_coord;
	t_coord		init_coord;
	int			i;
	int			j;
	int			k;

	if (!(tet_coord = (t_coord*)malloc(sizeof(*tet_coord) * 4)))
		return (NULL);
	k = 0;
	init_coord = start_coord(tet);
	i = init_coord.y;
	while (i < 4 && k < 4)
	{
		j = init_coord.x;
		while (j < 4 && k < 4)
		{
			if (tet[i][j] == '#')
			{
				tet_coord[k].y = i - init_coord.y;
				tet_coord[k].x = j - init_coord.x;
				k++;
			}
			j++;
		}
		i++;
	}
	return (tet_coord);
}

t_coord		*get_tet_list(int fd)
{
	t_coord *tet_coord;
	char	**tet;
	int		i;

	tet = read_tet(fd);
	tet_coord = tetri_coord(tet);
	i = 0;
	while (tet[i++])
		free(tet[i]);
	free(tet);
	tet = NULL;
	return (tet_coord);
}