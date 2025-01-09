/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:29:43 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/09 15:18:02 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(pipe_fd[READ_END]);
		dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
		execute_command(argv, envp);
	}
	else
	{
		close(pipe_fd[WRITE_END]);
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	write_to_pipe(int pipe_fd[2], char *limiter)
{
	char	*line;

	close(pipe_fd[READ_END]);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[WRITE_END], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[WRITE_END]);
}

void	handle_her_doc(char *limiter)
{
	pid_t	id;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error();
	id = fork();
	if (id == -1)
		error();
	if (id == 0)
	{
		write_to_pipe(pipe_fd, limiter);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipe_fd[WRITE_END]);
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		waitpid(id, NULL, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		if (ac >= 6 && ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open_file(av[ac - 1], 0);
			handle_her_doc(av[2]);
		}
		else
		{
			i = 2;
			outfile = open_file(av[ac - 1], 1);
			infile = open_file(av[1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < ac - 2)
			child_process(av[i++], env);
		dup2(outfile, STDOUT_FILENO);
		execute_command(av[ac - 2], env);
	}
	ft_printf("BAD ARGUMENTS \n");
}
