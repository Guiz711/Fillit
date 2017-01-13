/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:47:56 by jgourdin          #+#    #+#             */
/*   Updated: 2017/01/02 15:36:25 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		Error404(char **tetri)
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
        if (j != 3)
            return (0);
        ++i;
    }
	if (tetri[i + 1] == '\0' && x == 4)
		return (1);
	return (0);
}

