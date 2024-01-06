/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:32:32 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/06 08:32:34 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i])
	{
		path = ft_strnstr(env[i], "PATH", 4);
		if (path)
			return (path);
		i++;
	}
	return (NULL);
}

int	ft_execve(char **env, char **cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	if (find_path(env)[6] != '/')
		path = ft_split(&find_path(env)[5], ':');
	else
		path = cmd;
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], cmd[0]);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			if (execve(tmp, cmd, env) != -1)
			{
				free(tmp);
				break ;
			}
		}
		free(tmp);
	}
	ft_free(cmd);
	ft_free(path);
	return (-1);
}
