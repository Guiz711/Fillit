/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:00:39 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/18 18:00:31 by gmichaud         ###   ########.fr       */
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

char	**read_tet(int fd);
t_coord	*get_tet_list(int fd);

#endif