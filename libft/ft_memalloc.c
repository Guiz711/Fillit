/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:40:52 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/01 17:19:44 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*mem;
	char		*init;
	size_t		n;

	if (!(init = (char*)malloc(size)))
		return (NULL);
	n = 0;
	while (n < size)
	{
		init[n] = 0;
		n++;
	}
	mem = &init[0];
	return (mem);
}
