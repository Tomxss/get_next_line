/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:01:09 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/06/10 14:43:25 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_file(t_list **file, int fd)
{
	t_list	*tmp;	/*created a pointer*/

	tmp = *file;	/*pointer is pointing to *file*/
	while (tmp)		/*while tmp NOT eof*/
	{
		if ((int)tmp->content_size == fd) /*if at the last line*/
			return (tmp);
		tmp = tmp->next; /*equivalent of tmp++*/
	}
	tmp = ft_lstnew("\0", fd);/*allocating space for new lst*/
	ft_lstadd(file, tmp);/**/
	tmp = *file;
	return (tmp);
}
