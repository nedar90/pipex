/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:54:19 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/10 17:37:35 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipexbonus.h"

void	free_int(int ***p_fds, int n)
{
	while (n--)
		free((*p_fds)[n]);
	free(*p_fds);
}

void	init_p_fds(int ***p_fds, int ac)
{
	int		i;

	*p_fds = (int **)malloc((ac - 4) * sizeof(int *));
	if (!(*p_fds))
		return ;
	i = -1;
	while (++i < (ac - 4))
	{
		(*p_fds)[i] = (int *)malloc(2 * sizeof(int));
		if (!(*p_fds)[i])
		{
			free_int(p_fds, i);
			return ;
		}
	}
}

int	creat_childen(char **av, int **p_fds, char **env)
{
	int	num;
	int	pids;
	int	i;

	num = process_num(av);
	i = -1;
	while (++i < (num - 4))
	{
		pids = fork();
		if (pids == -1)
		{
			perror("Fork");
			return (-1);
		}
		if (pids == 0)
		{
			if (i == 0)
				first_child(av, p_fds, env);
			else
				children(av, p_fds, i - 1, env);
			return (-1);
		}
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int		**p_fds;
	int		i;

	if (ac < 5)
	{
		write(STDERR_FILENO, "Arguments\n", 10);
		exit(EXIT_FAILURE);
	}
	init_p_fds(&p_fds, ac);
	i = -1;
	while (++i < (ac - 4))
		if (pipe(p_fds[i]) == -1)
			ft_error("Pipe");
	creat_childen(av, p_fds, env);
	parent_bonus(av, p_fds, env);
	free_int(&p_fds, ac - 4);
	return (0);
}
