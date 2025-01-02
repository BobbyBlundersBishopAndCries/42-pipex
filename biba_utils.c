/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biba_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:29:30 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/02 04:00:06 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**return_path(char *env[])
{
	int		i;
	char	**path;

	i = 0;
	while (env[i] != NULL && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	path = ft_split(env[i] + 5, ':');
	return (path);
}

char	*create_full_path(char *path, char *command)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(path, "/");
	full_path = ft_strjoin(temp, command);
	free(temp);
	return (full_path);
}

char	*path_found(char *command, char *env[])
{
	char	**path;
	char	*full_path;
	int		i;

	path = return_path(env);
	if (NULL == path)
	{
		free(path);
		return (NULL);
	}
	i = 0;
	while (path[i] != NULL)
	{
		full_path = create_full_path(path[i], command);
		if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0)
		{
			free_array(path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(path);
	return (NULL);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	execute_command(char *command, char *env[])
{
	char	*p;
	char	**vector;

	if (!command)
		return ;
	vector = ft_split(command, ' ');
	if (!vector)
		return ;
	p = path_found(vector[0], env);
	if (p == NULL)
	{
		perror("command not found");
		free_array(vector);
		return ;
	}
	execve(p, vector, env);
	perror("execve error");
	free(p);
	free_array(vector);
}
