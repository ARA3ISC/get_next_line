/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:55:39 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/17 09:55:41 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_join(int fd, char *data)
{
	char	*buf;
	int		rd;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(data, '\n'))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (free(data), free(buf), NULL);
		if (rd == 0)
			break ;
		buf[rd] = '\0';
		data = ft_strjoin(data, buf);
	}
	free(buf);
	return (data);
}

char	*ft_split_data(char *data)
{
	char	*new_str;
	int		i;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	new_str = malloc(i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (data[i] && data[i] != '\n')
	{
		new_str[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
	{
		new_str[i] = data[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_get_chyata(char *data)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen(data);
	while (data[i] && data[i] != '\n')
		i++;
	if ((data[i] == '\0' || data[i + 1] == '\0'))
		return (free(data), NULL);
	new_str = malloc(len - i + 1);
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (data[i])
		new_str[j++] = data[i++];
	new_str[j] = '\0';
	free(data);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = read_join(fd, data);
	if (!data)
		return (NULL);
	line = ft_split_data(data);
	data = ft_get_chyata(data);
	return (line);
}
