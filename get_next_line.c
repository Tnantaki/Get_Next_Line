/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:55:17 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/20 17:10:35 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*nl = NULL;
	char	*ptr;
	char	*tmp;
	int		nb;
	int		len_nl;

	if (fd < 3)
		return (NULL);
	nb = BUFFER_SIZE;
	if (nl)
	{
		ptr = ft_strdup(nl);
		//free(nl);
	}
	else
		ptr = calloc(1, sizeof(char));
	// ptr = NULL;
	tmp = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	while (nb)
	{
		nb = read(fd, tmp, BUFFER_SIZE);
		len_nl = ft_check_newline(tmp);
		// printf("tmp : %s|\n", tmp);
		if (len_nl < nb)
		{
			// tmp = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
			ptr = ft_strjoin_n(ptr, tmp, len_nl);
			// printf("len : %d\n", len_nl);
			// printf("len buf : %d\n", BUFFER_SIZE - len_nl);
			nl = ft_strjoin_n(nl, tmp + len_nl, BUFFER_SIZE - len_nl);
			// printf("Hello\n");
			// printf("nl :%s\n",nl);
			break ;
		}
		else
			ptr = ft_strjoin_n(ptr, tmp, len_nl);
	}
	// if (!nb)
	// {}
	free(tmp);
	return (ptr);
}

int	main(void)
{
	char *str;
	int	fd;

	fd = open ("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	free (str);
	fd = close (fd);
}

