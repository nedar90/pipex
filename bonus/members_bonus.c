/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   members_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:44:18 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/10 17:36:54 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipexbonus.h"

void	parent_bonus(char **av, int **p_fds, char **env)
{
	int		fd;
	int		num;
	int		i;
	char	**cmd;

	num = process_num(av);
	ft_close(p_fds, 0, 'p', num - 4);
	fd = open(av[num - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd)
		ft_error("Outfile");
	if (dup2 (fd, STDOUT_FILENO) == -1)
		ft_error("Parent dup2");
	close(fd);
	if (dup2 (p_fds[num - 5][0], STDIN_FILENO) == -1)
		ft_error("Parent dup2");
	close(p_fds[num - 5][0]);
	cmd = ft_split(av[num - 2], ' ');
	if (ft_execve(env, cmd) == -1)
	{
		free_int(&p_fds, num - 4);
		ft_error("Execve");
	}
	i = -1;
	while (++i < (num - 4))
		wait (NULL);
}

void	close_first_child(int **p_fds, int num, char **cmd)
{
	close(p_fds[0][1]);
	free_int(&p_fds, num - 4);
	ft_free(cmd);
	ft_error("First dup2");
}

void	first_child(char **av, int **p_fds, char **env)
{
	int		fd;
	char	**cmd;
	int		num;

	num = process_num(av);
	ft_close(p_fds, 0, 'f', num - 4);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		ft_error("Infile");
	cmd = ft_split(av[2], ' ');
	if (dup2 (fd, STDIN_FILENO) == -1)
		close_first_child(p_fds, num, cmd);
	close(fd);
	if (dup2 (p_fds[0][1], STDOUT_FILENO) == -1)
		ft_error("First dup2");
	close(p_fds[0][1]);
	if (ft_execve(env, cmd) == -1)
	{
		free_int(&p_fds, num - 4);
		ft_error("Execve");
	}
}

void	children(char **av, int **p_fds, int n, char **env)
{
	char	**cmd;
	int		num;

	num = process_num(av);
	ft_close(p_fds, n, 'c', num - 4);
	cmd = ft_split(av[n + 3], ' ');
	if (dup2 (p_fds[n][0], STDIN_FILENO) == -1)
		ft_error("Children dup2");
	close(p_fds[n][0]);
	if (dup2 (p_fds[n + 1][1], STDOUT_FILENO) == -1)
		ft_error("Children dup2");
	close(p_fds[n + 1][1]);
	if (ft_execve(env, cmd) == -1)
	{
		free_int(&p_fds, num - 4);
		ft_error("Execve");
	}
}
