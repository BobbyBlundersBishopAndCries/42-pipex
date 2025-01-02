/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 04:00:18 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/02 04:03:05 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
char	**return_path(char *env[]);
char	*create_full_path(char *path, char *command);
char	*path_found(char *command, char *env[]);
void	free_array(char **array);
void	execute_command(char *command, char *env[]);
#endif