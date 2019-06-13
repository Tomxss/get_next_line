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

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static t_list	*file;
	int		i;
	int		ret;
	t_list		*curr;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);	//ERROR
	curr = get_file(&file, fd);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MALLCHECK((curr->content = ft_strjoin(curr->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_ccpy(line, curr->content, '\n');
	(i < (int)ft_strlen(curr->content))
		? curr->content += (i + 1)
		: ft_strclr(curr->content);
	return (1);
}
