/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:22:06 by pmelodi           #+#    #+#             */
/*   Updated: 2019/10/08 19:01:53 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*strjoined;

	i = 0;
	j = 0;
	if (!s1 || !s2 || !(strjoined = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[i])
	{
		strjoined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoined[j + i] = s2[j];
		j++;
	}
	strjoined[i + j] = '\0';
	return (strjoined);
}
