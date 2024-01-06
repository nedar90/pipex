/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 08:52:41 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/07 08:52:44 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_close_first_child(int **p_fds, int num)
{
	int		i;

	i = -1;
	while (++i < num)
	{
		if (i != 0)
			close(p_fds[i][1]);
		close(p_fds[i][0]);
	}
}

void	ft_close_parent(int **p_fds, int num)
{
	int		i;

	i = -1;
	while (++i < num)
	{
		if (i != num -1)
			close(p_fds[i][0]);
		close(p_fds[i][1]);
	}
}

void	ft_close_children(int **p_fds, int n, int num)
{
	int		i;

	i = -1;
	while (++i < num)
	{
		if (i != n)
			close(p_fds[i][0]);
		if (i != n + 1)
			close(p_fds[i][1]);
	}
}

void	ft_close(int **p_fds, int n, int flag, int num)
{
	if (flag == 'f')
		ft_close_first_child(p_fds, num);
	if (flag == 'c')
		ft_close_children(p_fds, n, num);
	if (flag == 'p')
		ft_close_parent(p_fds, num);
}
