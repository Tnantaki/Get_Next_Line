/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:28:11 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/06 23:28:14 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *str)
{
	int		readable;
	char	*tmp;

	readable = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	while (readable)
	{
		readable = read(fd, tmp, BUFFER_SIZE);
		if (readable <= 0)
			break ;
		str = ft_get_strjoin(str, tmp, readable);
		if (ft_get_check_nl(tmp, readable))
			break ;
	}
	free(tmp);
	return (str);
}

static char	*ft_cut_line(char *str, size_t len_str, size_t len_nl)
{
	char	*keep;
	size_t	i;
	size_t	j;

	if (len_nl < len_str)
	{
		i = 0;
		j = len_nl;
		keep = malloc(sizeof(char) * len_str - len_nl + 1);
		if (!keep)
			return (free(str), NULL);
		while (str[j])
			keep[i++] = str[j++];
		keep[i] = '\0';
		free (str);
		return (keep);
	}
	else
		return (free(str), NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[1024 - 3];
	char		*line;
	size_t		len_str;
	size_t		len_nl;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_get_check_nl(str[fd], ft_get_strlen(str[fd])))
		str[fd] = ft_read_line(fd, str[fd]);
	if (str[fd])
	{
		len_str = ft_get_strlen(str[fd]);
		len_nl = ft_get_strnl(str[fd]) + 1;
		line = ft_get_strdup(str[fd], line, len_str, len_nl);
		str[fd] = ft_cut_line(str[fd], len_str, len_nl);
	}
	return (line);
}

// int	main(void)
// {
// 	char *str;
// 	int	fd = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	printf("fd :%d\n", fd);
// 	str = get_next_line(fd);
// 	printf("len :%d\n", ft_get_strlen(str));
// 	printf("first :%s\n", str);
// 	free (str);
// 	// char c = 0;
// 	// read(fd, &c, 1);
// 	// printf ("printf :%c\n", c);
// 	str = get_next_line(fd);
// 	printf("second:%s\n", str);
// 	free (str);
// 	str = get_next_line(fd);
// 	printf("third :%s\n", str);
// 	free (str);
// 	str = get_next_line(fd);
// 	printf("fourth :%s\n", str);
// 	free (str);
// 	str = get_next_line(fd);
// 	printf("fifth :%s\n", str);
// 	free (str);
// 	fd = close (fd);
// }
