/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:00:39 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/13 18:46:30 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_sqr
{
	char		**map;
	int			size;
}				t_sqr;

t_list			*get_tet_list(int fd, t_list *tet_list);
int				solve(t_list *tet_list, t_sqr *sqr, char ltr);
void			print(t_sqr sqr);
void			darrdel(char ***dtab, size_t len);
int				find_square(t_list *tet_list);
int				wrgchar(char **tetri);
int				notetri(char **str);

#endif