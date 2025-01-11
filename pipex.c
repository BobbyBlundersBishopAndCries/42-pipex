/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:13 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/11 06:21:40 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_child(char *av[], int biba[2], char *env[])
{
	int	fd;

	close(biba[READ_END]);
	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
		ft_printf("failed to open file for reading : %s\n", strerror(errno));
	dup2(biba[WRITE_END], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(biba[WRITE_END]);
	close(fd);
	execute_command(av[2], env);
}

void	pid_second_child(char *av[], int biba[2], char *env[])
{
	int	fd;

	close(biba[WRITE_END]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_printf("failed to open file for writing : %s\n", strerror(errno));
	dup2(biba[READ_END], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(biba[READ_END]);
	close(fd);
	execute_command(av[3], env);
}

int	main(int ac, char *av[], char *env[])
{
	int		pipe_fd[2];
	pid_t	id[2];

	if (ac == 5)
	{
		if (!env || !(*env))
			error();
		if (pipe(pipe_fd) == -1)
			error();
		id[0] = fork();
		if (id[0] == -1)
			error();
		if (id[0] == 0)
			pid_child(av, pipe_fd, env);
		id[1] = fork();
		if (id[1] == -1)
			error();
		if (id[1] == 0)
			pid_second_child(av, pipe_fd, env);
		close(pipe_fd[READ_END]);
		close(pipe_fd[WRITE_END]);
		waitpid(id[0], NULL, 0);
		waitpid(id[1], NULL, 0);
	}
	return (0);
}
