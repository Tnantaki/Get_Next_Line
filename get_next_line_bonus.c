/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:00:52 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/23 14:42:15 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *str)
{
	int		readable;
	int		read_nl;
	char	*tmp;

	readable = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	while (readable)
	{
		readable = read(fd, tmp, BUFFER_SIZE);
		if (readable <= 0)
			break ;
		str = ft_strjoin(str, tmp, readable);
		read_nl = ft_newline_len(tmp, readable);
		if (read_nl < readable)
			break ;
	}
	free(tmp);
	return (str);
}

char	*ft_cut_line(char *str)
{
	char	*tmp;
	int		len;
	int		read_nl;

	len = ft_strlen(str);
	read_nl = ft_newline_len(str, len) + 1;
	if (read_nl < len)
	{
		tmp = str;
		str = ft_strjoin(NULL, str + read_nl, len - read_nl);
		free (tmp);
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[500];
	char		*line;
	int			len;
	int			read_nl;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = ft_strlen(str[fd]);
	read_nl = ft_newline_len(str[fd], len);
	if (read_nl == len)
		str[fd] = ft_read_line(fd, str[fd]);
	if (str[fd])
	{
		line = ft_strdup(str[fd]);
		str[fd] = ft_cut_line(str[fd]);
	}
	return (line);
}
/*
int	main(void)
{
	char *str;
	int	fd;
	fd = open("gnlTester/files/42_with_nl", O_RDONLY);
	printf("fd :%d\n", fd);
	str = get_next_line(fd);
	printf("len :%d\n", ft_strlen(str));
	printf("first :%s\n", str);
	free (str);
	// char c = 0;
	// read(fd, &c, 1);
	// printf ("printf :%c\n", c);
	str = get_next_line(fd);
	printf("second:%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("third :%s\n", str);
	free (str);
	fd = close (fd);
}
*/
