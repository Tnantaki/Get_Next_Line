/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:00:27 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/24 15:50:08 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_newline_len(char *str, int len);
char	*ft_strjoin(char *s1, char *s2, int lens2);
char	*ft_strdup(char *s1);

#endif
