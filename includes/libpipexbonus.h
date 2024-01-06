/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpipexbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:43 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/03 13:43:48 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIPEXBONUS_H
# define LIBPIPEXBONUS_H

# include "libft.h"

void	parent_bonus(char **av, int **p_fds, char **env);
void	first_child(char **av, int **p_fds, char **env);
void	children(char **av, int **p_fds, int n, char **env);
void	free_int(int ***p_fds, int n);
int		process_num(char **av);

#endif
