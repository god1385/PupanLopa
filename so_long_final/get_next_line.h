/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjanis <hjanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:08:32 by slucas-s          #+#    #+#             */
/*   Updated: 2022/03/07 20:55:16 by hjanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_linelen(char *line);
int		ft_newread(int fd, char **oldread);
char	*ft_getline(int len, char *read);
char	*ft_clearline(int len, char *read);
int		ft_strlen(const char *str);

#endif