/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:57:21 by tcoetzee          #+#    #+#             */
/*   Updated: 2019/06/10 12:12:16 by tcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 42

# define MALLCHECK(x) if (!x) return (-1);

int get_next_line(const int fd, char **line);
#endif
