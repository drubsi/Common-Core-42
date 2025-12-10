/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:45:10 by drubio-s          #+#    #+#             */
/*   Updated: 2025/02/27 18:54:59 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
int			ft_strlen(const char *str);
void		ft_zero(char *str, unsigned long int size );
void		*ft_calloc(unsigned long int n, unsigned long int size);
char		*ft_strjoin(const char *str1, const char *str2);
char		*ft_findchr(const char *str, int chr);
char		*ft_read(int fd, char *str);
char		*ft_line(char *str);
char		*ft_new_str(char *str);
#endif
