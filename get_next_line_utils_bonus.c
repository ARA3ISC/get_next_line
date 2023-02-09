/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:55:28 by maneddam          #+#    #+#             */
/*   Updated: 2022/11/17 09:55:30 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		len;
	int		i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *save_ln, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;

	if (save_ln == NULL)
		return (ft_strdup(buffer));
	new_str = malloc(ft_strlen(save_ln) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(save_ln), free(buffer), NULL);
	i = 0;
	while (save_ln[i])
	{
		new_str[i] = save_ln[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	free(save_ln);
	return (new_str);
}
