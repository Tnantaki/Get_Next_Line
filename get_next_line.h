/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:52:49 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/23 10:31:47 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_newline_len(char *str, int len);
char	*ft_strjoin(char *s1, char *s2, int lens2);
char	*ft_strdup(char *s1);

#endif
