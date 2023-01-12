/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:27:50 by mayache-          #+#    #+#             */
/*   Updated: 2022/11/09 16:42:06 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		str_len(char *str);
char	*str_chr(const char *str, int chr);
char	*str_join(char *s1, char *s2);
char	*write_save(char *buffer, int fd);
char	*ft_get_line(char *buff);
char	*clean_last_line(char *buff);
char	*get_next_line(int fd);
#endif
