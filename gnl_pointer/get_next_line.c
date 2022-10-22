/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:55:17 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/23 00:41:17 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *str)
{
	int		readable;
	int		read_nl;
	char	*tmp;

	readable = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (readable)
	{
		readable = read(fd, tmp, BUFFER_SIZE);
		if (readable <= 0)
			break ;
		tmp[readable] = '\0';
		// printf("readable :%d\n", readable);
		str = ft_strjoin(str, tmp, ft_strlen(tmp));
		read_nl = ft_newline_len(tmp, readable);
		if (read_nl < readable)
			break ;
	}
	free (tmp);
	return (str);
}

char	*ft_cut_line(char *str)
{
	char *tmp;
	int	len;
	int	read_nl;

	len = ft_strlen(str);
	read_nl = ft_newline_len(str, len);
	if (read_nl < len)
	{
		tmp = str;
		str = ft_strjoin(NULL, str + read_nl, len - read_nl);
		free (tmp);
	}
	else
	{
		free (str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			len;
	int			read_nl;

	line = NULL;
	if (fd < 3 || BUFFER_SIZE <= 0)
		return (NULL);
	len = ft_strlen(str);
	read_nl = ft_newline_len(str, len);
	if (read_nl == len)
		str = ft_read_line(fd, str);
	if (str)
	{
		line = ft_strdup(str);
		str = ft_cut_line(str);
	}
	return (line);
}

int	main(void)
{
	char *str;
	int	fd;
	fd = open ("gnlTester/files/41_with_nl", O_RDONLY);
	printf("fd :%d\n", fd);
	str = get_next_line(fd);
	printf("first :%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("second:%s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("third :%s\n", str);
	free (str);
	fd = close (fd);
}

