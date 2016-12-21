/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:48:29 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/18 11:39:15 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** GET_NEXT_LINE :
**
** int get_next_line(int fd, char **line)
**
** get_next_line reads from a file descriptor and forms a line.
** A line ends if a \n is encountered. You can get all the lines of
** a file descriptor by successive calls to get_next_line.
**
** Return values :
** get_next_line returns 1 if a line was read, 0 if there is nothing
** to be read, or -1 if an error occured.
*/

#include "get_next_line.h"

/*
** stockoline processes whatever is in the stock to create a new line and 
** adjust the stock for the next get_next_line call.
** Forms a new line and returns 1 if a \n was found,
** 0 if no \n has been found, or -1 if an error occured.
*/

static int	stocktoline(char **stock, char **line)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while ((*stock)[len] && (*stock)[len] != '\n')
		len++;
	if (!(*line = ft_strnew(sizeof (**line) * len)))
		return (-1);
	*line = ft_strncpy(*line, *stock, len);
	if (!(*stock)[len])
	{
		ft_strdel(stock);
		return (0);
	}
	if (!(tmp = ft_strnew(sizeof(*tmp) * (ft_strlen(*stock) - len - 1))))
		return (-1);
	tmp = ft_strcpy(tmp, *stock + len + 1);
	free(*stock);
	*stock = tmp;
	return (1);
}


/*
** bufftostock copies the content from buffer into stock.
** Returns 1 if it meets a \n, 0 if no \n was found or
** -1 if an error occured.
*/

static int	bufftostock(char *buff, char **stock, size_t size)
{
	size_t	o_len;

	o_len = (*stock ? ft_strlen(*stock) : 0);
	if(!(*stock = ft_realloc(*stock, o_len + 1, o_len + size + 1)))
		return (-1);
	while (size--)
	{
		(*stock)[o_len++] = *buff;
		buff++;
	}
	(*stock)[o_len] = '\0';
	return (strchr(*stock, '\n') ? 1 : 0);
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*stock = NULL;
	ssize_t		ret;
	int			flg;

	flg = (stock && ft_strchr(stock, '\n')) ? 1 : 0;
	if(!(buff = ft_memalloc(BUFF_SIZE)))
		return (-1);
	while (!flg && (ret = read(fd, buff, BUFF_SIZE)) > 0)
		flg = bufftostock(buff, &stock, ret);
	ft_memdel((void**)&buff);
	if (flg == -1 || ret == -1)
		return (-1);
	if (flg > 0)
		flg = stocktoline(&stock, line);
	if (flg == 0 && ret == 0)
		return (0);
	return (1);
}