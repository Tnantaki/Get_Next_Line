/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:01:24 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/23 14:01:46 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_newline_len(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (i < len)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int lens2)
{
	char	*dst;
	int		lens1;
	int		i;
	int		j;

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
	free(s1);
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	i;
	size_t	len;
	size_t	len_nl;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	len_nl = ft_newline_len(s1, len) + 1;
	dst = malloc((sizeof(char)) * (len_nl + 1));
	if (!dst)
		return (NULL);
	while (len_nl--)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
