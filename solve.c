/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:04:52 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/10 15:54:45 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Writes a tetriminos into the square to a precised position.
** Uses the specified letter for the tetriminos writing.
*/

static void		wrt_tet(t_coord *tet, t_sqr *sqr, int pos, char ltr)
{
	int x;
	int y;
	int i;

	x = pos % sqr->size;
	y = pos / sqr->size;
	i = 0;
	while (i < 4)
	{
		sqr->map[y + tet[i].y][x + tet[i].x] = ltr;
		i++;
	}
}

/*
** Deletes a tetriminos from the square. It verifies if the tetriminos
** has been written beforehand to prevent any unwanted deletion.
*/

static void		del_tet(t_coord *tet, t_sqr *sqr, int pos, char ltr)
{
	int x;
	int y;
	int i;

	x = pos % sqr->size;
	y = pos / sqr->size;
	i = 0;
	while (i < 4)
	{
		if (sqr->map[y + tet[i].y][x + tet[i].x] == ltr)
			sqr->map[y + tet[i].y][x + tet[i].x] = '.';
		i++;
	}
}

/*
** Checks if the tetriminos fits in the specified position
** without overflowing the square limits nor colliding into another
** tetriminos.
** Returns 1 if the tetriminos fits in this position,
** or 0 if it doesn't.
*/

static int		check_tet(t_coord *tet, t_sqr *sqr, int pos)
{
	int	x;
	int	y;
	int	i;

	x = pos % sqr->size;
	y = pos / sqr->size;
	i = 0;
	while (i < 4)
	{
		if (y + tet[i].y > sqr->size || x + tet[i].x > sqr->size)
			return (0);
		if (sqr->map[y + tet[i].y][x + tet[i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

/*
** Finds if the tetriminos from tet_list can be assembled into
** a given square. It uses a backtracking algorythm for this.
** Returns 1 if a solution was found, or 0 if no solution was found.
*/

int				solve(t_list *tet_list, t_sqr *sqr, char ltr)
{
	int		pos;
	t_coord *tet;

	if (!tet_list)
	return (1);
	tet = (t_coord*)tet_list->content;
	pos = 0;
	while (pos < sqr->size * sqr->size)
	{
		if (check_tet(tet, sqr, pos))
		{
			wrt_tet(tet, sqr, pos, ltr);
			if (solve(tet_list->next, sqr, ltr + 1))
				return (1);
		}
		else
			del_tet(tet, sqr, pos, ltr);
		pos++;
	}
	return (0);
}