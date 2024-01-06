/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:25:31 by nrajabia          #+#    #+#             */
/*   Updated: 2022/12/16 17:25:48 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		num1;
	int		num2;

	if (!s2 || !*s2)
		return (NULL);
	if (s2[0] == '/')
		return (s2);
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	num1 = 0;
	while (s1 && s1[num1])
	{
		str[num1] = s1[num1];
		num1++;
	}
	str[num1++] = '/';
	num2 = 0;
	while (s2[num2] != '\0')
		str[num1++] = s2[num2++];
	str[num1] = '\0';
	return (str);
}
