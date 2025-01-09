/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohabid <mohabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:39:43 by mohabid           #+#    #+#             */
/*   Updated: 2025/01/09 14:59:12 by mohabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int flag)
{
	int	fd;

	fd = 0;
	if (flag == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (flag == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (flag == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		error();
	return (fd);
}

void	error(void)
{
	perror("error\n");
	exit(EXIT_FAILURE);
}
