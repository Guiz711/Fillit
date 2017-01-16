/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:50:09 by jgourdin          #+#    #+#             */
/*   Updated: 2017/01/16 15:57:46 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		search(char **str, int i, int j)
{
	int	k;

	k = 0;
	if (i > 0)
	{
		if (str[i - 1][j] == '#')
			k++;
	}
	if (j > 0)
	{
		if (str[i][j - 1] == '#')
			k++;
	}
	if (i < 3)
	{
		if (str[i + 1][j] == '#')
			k++;
	}
	if (j < 3)
	{
		if (str[i][j + 1] == '#')
			k++;
	}
	return (k);
}

int		notetri(char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '#')
				k = k + search(str, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (k == 6 || k == 8)
		return (1);
	return (0);
}
