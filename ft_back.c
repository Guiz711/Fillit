/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:21:43 by jgourdin          #+#    #+#             */
/*   Updated: 2017/01/10 15:39:27 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct		s_sqr
{
	char			**map;
	size_t			size;
}					t_sqr;

size_t		ft_size(size_t nb)
{
	size_t	i;

	i = 1;
	if ((int)nb < 0)
		return (0);
	while (i * i < nb)
		++i;
	return (i);
}

t_sqr	ft_square(t_list *tet_list, int i)
{
	size_t		size;
	t_sqr		square;

	size = lst_len(tet_list);
	square.size = ft_square(size);
	square.map = malloc(sizeof(char) * square.size + i);
	return (square);
}

void	ft_fillit(t_list *tet_list)
{
	int			i;
	char		let;
	int			check;
	t_sqr		square;

	i = 0;
	let = 65;
	while (check)
	{
		square = ft_square(tet_list, i)
		if (solve(tet_list, &square, let) == 0)
		{
			free(square);
			++i;
		}
		else
			check = 1;
	}
	print(square);
}
