/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:39:54 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/06/27 15:47:53 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ccpy(char **line, char *content, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

t_list	*get_curr(int fd, t_list **hlist)
{
	t_list	*tmp;

	if (!hlist)
		return (NULL);
	tmp = *hlist;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(hlist, tmp);
	return (tmp);
}

int		safe_read(const int fd, char **content)
{
<<<<<<< HEAD
	int		res;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((res = read(fd, buf, BUFF_SIZE)))
	{
		buf[res] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
=======
	char		buf[BUFF_SIZE + 1];
	static t_list	*file;	//declares a starting struct like *head
	int		i;
	int		ret;
	t_list		*curr;	//declares a current struct

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))	// 0 = read
		return (-1);	//ERROR				// 1 = write
	curr = get_file(&file, fd);// recieves the completed struct// 2 = read
	CHECK((*line = ft_strnew(1)));			// 4 = read-write
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		CHECK((curr->content = ft_strjoin(curr->content, buf)));
>>>>>>> 884442cfd53ad1a3d71863b2a41a4b94e1f984f3
		if (ft_strchr(buf, '\n'))
			break;
	}
<<<<<<< HEAD
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			res;
	static t_list	*hlist;
	t_list			*curr;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
			(!(curr = get_curr(fd, &hlist))))
		return (-1);
	tmp = curr->content;
	res = safe_read(fd, &tmp);
	curr->content = tmp;
	if (!res && !*tmp)
		return (0);
	res = ccpy(line, curr->content, '\n');
	tmp = curr->content;
	if (tmp[res] != '\0')
	{
		curr->content = ft_strdup(&((curr->content)[res + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
=======
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);	//completed
	i = ft_ccpy(line, curr->content, '\n');
	(i < (int)ft_strlen(curr->content))
		? curr->content += (i + 1)
		: ft_strclr(curr->content);
	return (1);//has been read
>>>>>>> 884442cfd53ad1a3d71863b2a41a4b94e1f984f3
}
