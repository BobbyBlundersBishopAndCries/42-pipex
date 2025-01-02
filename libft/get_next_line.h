/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:46 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/01 22:13:38 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*extract_line(char *buffer);
char	*new_line(char *buffer);
size_t	ft_strlen_two(const char *s);
char	*ft_strchr_two(const char *s, int c);
char	*ft_strjoin_two(const char *s1, const char *s2);
#endif