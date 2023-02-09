/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:55:16 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/17 09:55:18 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_join(char *save_ln, int fd)
{
	char	*buffer;
	int		r;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(save_ln, '\n') == NULL)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (free(buffer), free(save_ln), NULL);
		if (r == 0)
			break ;
		buffer[r] = '\0';
		save_ln = ft_strjoin(save_ln, buffer);
	}
	free(buffer);
	return (save_ln);
}

char	*get_my_line(char *save_ln)
{
	char	*new_str;
	int		i;

	i = 0;
	while (save_ln[i] && save_ln[i] != '\n')
		i++;
	if (save_ln[i] == '\n')
		i++;
	new_str = malloc(i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (save_ln[i] && save_ln[i] != '\n')
	{
		new_str[i] = save_ln[i];
		i++;
	}
	if (save_ln[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = '\0';
	return (new_str);
}

char	*get_chyata(char *save_ln)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(save_ln);
	while (save_ln[i] && save_ln[i] != '\n')
		i++;
	if ((save_ln[i] == '\0' || save_ln[i + 1] == '\0'))
		return (free(save_ln), NULL);
	new_str = malloc(len - i + 1);
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (save_ln[i])
		new_str[j++] = save_ln[i++];
	new_str[j] = '\0';
	free(save_ln);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*save_ln[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	save_ln[fd] = read_join(save_ln[fd], fd);
	if (!save_ln[fd])
		return (NULL);
	line = get_my_line(save_ln[fd]);
	save_ln[fd] = get_chyata(save_ln[fd]);
	return (line);
}
