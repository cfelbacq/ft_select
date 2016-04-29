/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:06:33 by cfelbacq          #+#    #+#             */
/*   Updated: 2016/01/12 13:33:45 by cfelbacq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		count_len_line(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static	int		check_endline(char *s, int ret)
{
	int i;

	i = 0;
	if (ret == -2)
		return (1);
	if (ret == 0)
		return (0);
	while (i < ret)
	{
		if (s[i] == '\n' || s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static	char	*read_file(int fd, char *s)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	tmp = NULL;
	ret = -2;
	while (check_endline(buf, ret) == 1 && ret != 0)
	{
		tmp = s;
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		if ((s = ft_strjoin(s, buf)) == NULL)
			return (NULL);
		ft_strdel(&tmp);
	}
	return (s);
}

static	char	*fill_tab(char *line, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	s = (char *)ft_memmove(s, s + count_len_line(line) + 1, ft_strlen(s));
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	char static *s;

	if (line == NULL)
		return (-1);
	if (s == NULL)
		if ((s = (char *)malloc(sizeof(char))) == NULL)
			return (-1);
	if ((s = read_file(fd, s)) == NULL)
		return (-1);
	if ((*line = (char *)ft_memalloc(sizeof(char)\
		* count_len_line(s) + 1)) == NULL)
		return (-1);
	if (s[0] != '\0')
		*line = fill_tab(*line, s);
	else
	{
		ft_strdel(&s);
		return (0);
	}
	return (1);
}
