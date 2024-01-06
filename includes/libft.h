/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:43 by nrajabia          #+#    #+#             */
/*   Updated: 2023/07/03 13:43:48 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>

void	ft_close(int **p_fd, int n, int flag, int num);
void	ft_free(char **str);
void	ft_error(char *err);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_execve(char **env, char **cmd);
size_t	ft_strlen(const char *s);

#endif
