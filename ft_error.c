/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:47:56 by jgourdin          #+#    #+#             */
/*   Updated: 2017/01/16 16:24:32 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		wrgchar(char **tetri)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			if (tetri[i][j] != '.' && tetri[i][j] != '#')
				return (0);
			if (tetri[i][j] == '#')
				++x;
			++j;
		}
		if (j != 4)
			return (0);
		++i;
	}
	if (x == 4)
		return (1);
	return (0);
}
