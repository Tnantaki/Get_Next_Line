/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:55:17 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/21 00:12:27 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(char *str, int count_read)
{
	int	i;

	i = 0;
	while (i < count_read)
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	nl[BUFFER_SIZE];
	char	*ptr;
	char	*tmp;
	int		count_read;

	count_read = 1;
	ptr = (char *)malloc(sizeof(char));
	*ptr = 0;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*nl)
		ptr = ft_strjoin_n(ptr, nl, ft_strlen(nl));
	while (count_read)
	{
		count_read = read(fd, tmp, BUFFER_SIZE);
		count_read = ft_check_newline(tmp, count_read);
		ptr = ft_strjoin_n(ptr, tmp, count_read);
		if (count_read < BUFFER_SIZE)
		{
			ft_strcpy(nl, tmp + count_read);
			break ;
		}
	}
	free(tmp);
	return (ptr);
}
/*
int	main(void)
{
	char *str;
	int	fd;

	fd = open ("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	free (str);
	fd = close (fd);
}
*/
