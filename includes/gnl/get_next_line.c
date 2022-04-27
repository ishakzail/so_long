/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:23:38 by izail             #+#    #+#             */
/*   Updated: 2022/04/27 18:15:50 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;
	char	*p;

	i = 0;
	str = (char *)s1;
	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	char	buff[2];
	char	*line;
	int		n;
	void	*d_ptr;

	if (fd < 0)
		return (NULL);
	buff[0] = 0;
	buff[1] = 0;
	line = ft_strdup("");
	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, 1);
		if (n <= 0)
			continue ;
		d_ptr = line;
		line = ft_strjoin(line, buff);
		free(d_ptr);
		if (buff[0] == '\n')
			return (line);
	}
	if (line && !*line)
		return (free(line), NULL);
	return (line);
}
