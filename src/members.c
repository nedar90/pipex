/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   members.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:44:18 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/07 12:44:38 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

/**
 * @brief Parent reads data frome pipe and creats output file
 *
 * @p_fd[1] write, close
 * @p_fd[0] read from pipe
 **/
void	parent(char **av, int *p_fd, char **env)
{
	int		fd;
	char	**cmd;

	close(p_fd[1]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd)
	{
		write(STDERR_FILENO, "Outfile\n", 10);
		exit(EXIT_FAILURE);
	}
	if (dup2 (fd, STDOUT_FILENO) == -1)
		ft_error("Parent1 dup2");
	close(fd);
	if (dup2 (p_fd[0], STDIN_FILENO) == -1)
		ft_error("Parent2 dup2");
	close(p_fd[0]);
	cmd = ft_split(av[3], ' ');
	if (ft_execve(env, cmd) == -1)
		ft_error("Execve");
	wait (NULL);
}

/**
 * @brief child read from imput file and write into pipe
 *
 * @p_fd[1] write into pipe
 * @p_fd[0] read, close
 **/
void	child(char **av, int *p_fd, char **env)
{
	int		fd;
	char	**cmd;

	close(p_fd[0]);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		ft_error("Infile");
	cmd = ft_split(av[2], ' ');
	if (dup2 (fd, STDIN_FILENO) == -1)
	{
		ft_free(cmd);
		close(p_fd[1]);
		ft_error("First dup2");
	}
	close(fd);
	if (dup2 (p_fd[1], STDOUT_FILENO) == -1)
		ft_error("First dup2");
	close(p_fd[1]);
	if (ft_execve(env, cmd) == -1)
		ft_error("Execve");
}
