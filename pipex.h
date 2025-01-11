/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 04:00:18 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/11 06:25:42 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END 0
# define WRITE_END 1

# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

void	execute_command(char *command, char *env[]);
void	error(void);
int		open_file(char *argv, int flag);
#endif