/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:30:40 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/13 16:43:02 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void		tab_dell(char ***tet)
{
	size_t	i;

	i = 0;
	if (tet)
	{
		while (++i < 5)
			ft_memdel (**tet);
		free (*tet);
		*tet = NULL;
	}
}

char		**read_tet(char *file)
{
	char	**tet;
	int		line_cnt;
	int		flg;
	int		fd;

	tet = (char**)memalloc(sizeof(*tet) * 5);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	line_cnt  = 0;
	while ((flg = get_next_line(fd, &tet[line_cnt])) > 0 && line_cnt < 4)
	{
		line_cnt++;
		if (!tet[line_cnt])
			break ;
	}
	if (flg == -1 || line_cnt != 4)
	{
		tab_dell(&tet);
		return (NULL);
	}
	return (tet);
}

coord		*start_coord(char **tet, coord *tet_coord)
{
	size_t	i;
	size_t	j;

	*tet_coord.x = 0;
	*tet_coord.y = 0;
	i = 0;
	while (tet[++i])
	{
		j = 0;
		while (tet[i][++j])
		{
			if (test[i][j] == '#')
			{
				if (j < *tet_coord.x)
					*tet_coord.x = j;
				if (i < *tet_coord.y)
					*tet_coord.y = i;
			}
		}
	}
}