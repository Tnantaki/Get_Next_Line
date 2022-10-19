/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:55:17 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/19 08:24:46 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*ptr;
	char	*tmp;
	int		i;
	int		nb;

	nb = 1;
	size = 1;
	while (nb)
	{
		i = 0;
		ptr = calloc(size + 1, 1);
		tmp = ptr;
		nb = read (fd, ptr, 1);
		while (tmp[i])
		{
			ptr[i] = tmp[i];
			i++;
		}
		size++;
		printf("nb :%zu", nb);
		// printf("str :%s %p\n", ptr, &ptr);
	}
	// bf_size--;
	// ptr - bf_size;
	// str = (char *)malloc(sizeof(char) * buffer_size);
	// nb = read (fd, str, 100);
	// printf("nb :%zu\n", nb);
	// printf("bf_size :%zu\n", bf_size);
	// printf("str :%s\n", ptr);
	return (ptr);
}

int	main(void)
{
	char *str;
	int	fd;
	fd = open ("fdfile.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
