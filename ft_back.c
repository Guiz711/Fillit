/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:21:43 by jgourdin          #+#    #+#             */
/*   Updated: 2017/01/10 17:39:33 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		lst_len(t_list *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

static int		ft_size(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb * 4)
		++i;
	return (i);
}

static t_sqr	ft_square(int size)
{
	t_sqr		square;
	int			i;
	int			j;
	
	square.size = size;
	if (!(square.map = (char**)ft_memalloc(sizeof(char*) * size + 1)))
		return (square);
	i = 0;
	while (i < size)
	{
		if (!(square.map[i] = (char*)ft_memalloc(sizeof(char) * size + 1)))
		{
			square.map = NULL;
			return (square);
		}
		j = 0;
		while (j < size)
			square.map[i][j++] = '.';
		i++;
	}
	square.map[i] = NULL;
	return (square);
}

int				find_square(t_list *tet_list)
{
	int			size;
	int			check;
	t_sqr		square;

	size = ft_size(lst_len(tet_list));
	check  = 0;
	while (!check)
	{
		square = ft_square(size);
		if (!square.map)
			return (0);
		if (!solve(tet_list, &square, 'A'))
		{
			print(square);
			return (1);
			//darrdel(&square.map, size);
			//++size;
		}
		else
			check = 1;
	}
	print(square);
	return (1);
}
