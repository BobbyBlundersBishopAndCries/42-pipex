/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:44:13 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/02 19:08:32 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_child(char *av[], int biba[2], char *env[])
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
		ft_printf("failed to open file for reading : %s\n", strerror(errno));
	dup2(biba[WRITE_END], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(biba[WRITE_END]);
	close(biba[READ_END]);
	close(fd);
	execute_command(av[2], env);
}

void	pid_parent(char *av[], int biba[2], char *env[])
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		ft_printf("failed to open file for writing : %s\n", strerror(errno));
	dup2(biba[READ_END], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(biba[WRITE_END]);
	close(biba[READ_END]);
	close(fd);
	execute_command(av[3], env);
}

int	main(int ac, char *av[], char *env[])
{
	int		pipe_fd[2];
	pid_t	id;

	if (ac == 5)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe creation error");
			exit(EXIT_FAILURE);
		}
		id = fork();
		if (id == -1)
		{
			perror("forking process error");
			exit(EXIT_FAILURE);
		}
		if (id == 0)
			pid_child(av, pipe_fd, env);
		waitpid(id, NULL, 0);
		pid_parent(av, pipe_fd, env);
	}
	else
		ft_printf("ERROR BAD NUMBER OF ARGUMENTS");
}
