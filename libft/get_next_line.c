/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:57:35 by ayghazal          #+#    #+#             */
/*   Updated: 2020/02/13 14:39:52 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_search(const char *s, int c)
{

	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return(1);
		i++;
	}
	return(0);
}

static char		*reading(char *str, int fd)
{
	char		*p;
	char		*buffer;
	int			res;

	if (!(buffer = malloc(sizeof(char) * 1000 + 1)))
		return (NULL);
	while ((res = read(fd, buffer, 1000)))
	{
		buffer[res] = '\0';
		p = str;
		str = ft_strjoin(str, buffer);
		free(p);
		if (ft_search(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

static int				norminette(char **str, char **line, char **tmp)
{
	int i;

	i = 0;
	while (((*str)[i]) != '\0')
	{
		if (((*str)[i]) == '\n')
			break ;
		i++;
	}
	*tmp = *line;
	*line = ft_substr(*str, 0, i);
	free(*tmp);
	if ((*str)[i] == '\0')
	{
		*tmp = *str;
		*str = NULL;
		free(*tmp);
		return (0);
	}
	*tmp = *str;
	*str = ft_strdup(*str + i + 1);
	free(*tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		*tmp;
	static char	*str;

	if (fd < 0 || line == NULL || read(fd, NULL, 0))
		return (-1);
	*line = ft_strdup("");
	if (!str)
		str = ft_strdup("");
	if ((str = reading(str, fd)) == NULL)
		return (-1);
	if (str)
	{
		return (norminette(&str, &(*line), &tmp));
	}
	return (0);
}
