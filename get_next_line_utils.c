/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:33:29 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/20 17:12:00 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_n(char *s1, char *s2, size_t lens2)
{
	char	*dst;
	size_t	lens1;
	size_t	i;
	size_t	j;

	// printf("tmp a: %s\n", s2);
	if (!s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	dst = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (lens1--)
		dst[i++] = s1[j++];
	j = 0;
	while (lens2--)
		dst[i++] = s2[j++];
	dst[i] = '\0';
	//free(s2);
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = count * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = 0;
	return (str);
}
char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc((sizeof(char)) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
