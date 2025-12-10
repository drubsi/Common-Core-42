/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:45:10 by drubio-s          #+#    #+#             */
/*   Updated: 2025/03/05 18:28:40 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
int			ft_strlen_gnl(const char *str);
void		ft_zero(char *str, unsigned long int size );
void		*calloc_gnl(unsigned long int n, unsigned long int size);
char		*ft_strjoin(const char *str1, const char *str2);
char		*ft_findchr(const char *str, int chr);
char		*ft_read(int fd, char *str);
char		*ft_line(char *str);
char		*ft_new_str(char *str);
#endif
