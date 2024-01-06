/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:19 by nrajabia          #+#    #+#             */
/*   Updated: 2023/06/24 14:54:25 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

int	creat_child(char **av, int *p_fds, char **env)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		return (-1);
	}
	if (pid == 0)
	{
		child(av, p_fds, env);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	p_fd[2];

	if (ac != 5)
	{
		write(STDERR_FILENO, "Arguments\n", 10);
		exit(EXIT_FAILURE);
	}
	if (pipe(p_fd) == -1)
		ft_error("Pipe");
	creat_child(av, p_fd, env);
	parent(av, p_fd, env);
	return (0);
}
