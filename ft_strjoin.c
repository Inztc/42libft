/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:38:18 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:29:34 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	string = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		string[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		string[j++] = s2[i];
		i++;
	}
	string[j] = 0;
	return (string);
}
