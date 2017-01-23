/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:30:40 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/19 16:31:39 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		darrdel(char ***dtab, size_t len)
{
	size_t	i;

	i = 0;
	if (dtab)
	{
		while (i < len)
		{
			if ((*dtab)[i])
				free((*dtab)[i]);
			i++;
		}
		free(*dtab);
		*dtab = NULL;
	}
}

/*
** Creates 2D tab with one tetriminos grid inside.
** Returns the 2D tab, or a NULL pointer if an error occured.
** tet[0] will be NULL with a valid file if the end of file
** has been reached.
*/

int			read_tet(int fd, char ***tet)
{
	char	*trash;
	int		line_cnt;
	int		flg;

	trash = NULL;
	if (!(*tet = (char**)malloc(sizeof(*tet) * 5)))
		return (-1);
	line_cnt = 0;
	while (line_cnt < 5)
		(*tet)[line_cnt++] = NULL;
	line_cnt = 0;
	while (line_cnt < 4 && (flg = get_next_line(fd, &(*tet)[line_cnt])) > 0)
		line_cnt++;
	if (flg > 0)
		flg = get_next_line(fd, &trash);
	if (line_cnt != 4 || (trash && trash[0]) || flg == -1 || !notetri(*tet)
		|| !wrgchar(*tet))
		flg = -1;
	free(trash);
	return (flg);
}

/*
** Warning, this function must receive only valid files!
** Returns the initial coords to calculate the absolute tetriminos coords.
** The coords are stocked in  t_coord structure.
*/

t_coord		start_coord(char **tet)
{
	t_coord init_coord;
	int		i;
	int		j;

	init_coord.x = 3;
	init_coord.y = 3;
	i = 0;
	while (tet[i])
	{
		j = 0;
		while (tet[i][j])
		{
			if (tet[i][j] == '#' && j < init_coord.x)
				init_coord.x = j;
			if (tet[i][j] == '#' && i < init_coord.y)
				init_coord.y = i;
			j++;
		}
		i++;
	}
	return (init_coord);
}

/*
** Warning, this function must receive only valid files.
** Uses the start_coord function to calculate the current tetri coords.
** Returns a t_coord type array containing each block absolute coords.
*/

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
	while (tet[i] && k < 4)
	{
		j = init_coord.x;
		while (tet[i][j] && k < 4)
		{
			if (tet[i][j++] == '#')
			{
				tet_coord[k].y = i - init_coord.y;
				tet_coord[k++].x = j - 1 - init_coord.x;
			}
		}
		i++;
	}
	return (tet_coord);
}

/*
** Calls the read_tet function and all the file validation functions.
** If the file is valid, creates a t_coord arrays list to stock a the
** tetriminos coords.
** Returns the chained list, or a NULL pointer if an error occured.
*/

int		get_tet_list(int fd, t_list **tet_list)
{
	t_coord	*tet_coord;
	char	**tet;
	int		ret;
	int		flg;

	flg = 1;
	tet = NULL;
	ret = read_tet(fd, &tet);
	if (ret == 1)
		flg = get_tet_list(fd, tet_list);
	if (ret == -1 || !flg)
	{
		darrdel(&tet, 5);
		return (0);
	}
	tet_coord = tetri_coord(tet);
	ft_lstadd(tet_list, ft_lstnew(tet_coord, sizeof(t_coord) * 4));
	darrdel(&tet, 5);
	return (1);
}
