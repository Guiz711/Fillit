/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:38:03 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/16 15:59:39 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	tablen(t_coord **tab)
{
	size_t	len;

	len = 0;
	while (tab[len])
		++len;
	return(len);
}

size_t	lstlen(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

int		check_tet(t_list *tet_list, t_coord **tet_sol, int pos, int max)
{
	int	blk;
	int blk_x;
	int	blk_y;
	int i;
	int j;

	blk = 4;
	while (blk--)
	{
		blk_x = ((t_coord*)tet_list->content)[blk].x + (pos % max);
		blk_y = ((t_coord*)tet_list->content)[blk].y + pos / max;
		i = 0;
		while (tet_sol[i])
		{
			j = 0;
			while (j < 4)
			{
				if (blk_x == tet_sol[i][j].x || blk_y == tet_sol[i][j].y)
					return (0);
				++j;
			}
			++i;
		}
	}
	return (1);
}

void	place_tet(t_list *tet_list, t_coord **tet_sol, int pos, int max)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet_sol[i])
		i++;
	tet_sol[i] = (t_coord*)malloc(sizeof(t_coord) * 4);
	while (j < 4)
	{
		tet_sol[i][j].x = ((t_coord*)tet_list->content)[j].x + pos % max;
		tet_sol[i][j].y = ((t_coord*)tet_list->content)[j].y + pos / max;
		j++;
	}
}

void	del_sol(t_coord **tet_sol)
{
	if (!tet_sol[0])
		return ;
	while (*tet_sol != NULL)
		tet_sol++;
	tet_sol--;
	free(*tet_sol);
	*tet_sol = NULL;
}

int		solve(t_list *tet_list, t_coord **tet_sol, int pos, int max)
{
	//ft_putnbr(tablen(tet_sol));
	//t_list *tmp;

	//tmp = tet_list;
	if (tablen(tet_sol) == 4)
		return (1);
	while (tet_list)
	{
		//ft_putnbr(check_tet(tet_list, tet_sol, pos, max));
		if (check_tet(tet_list, tet_sol, pos, max))
		{
			place_tet(tet_list, tet_sol, pos, max);
			if (tet_sol[0])
				print(tet_sol);
			if (solve(tet_list->next, tet_sol, pos++, max))
				return (1);
		}
		tet_list = tet_list->next;
	}
	if (pos / max == max && pos % max == max)
		del_sol(tet_sol);
	//if (solve(tet_list, tet_sol, pos++, max))
	//	return (1);
	ft_putchar('a');
	return (0);
}
