/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:19:33 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:45:49 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && char_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_set(s1[end - 1], set))
		end--;
	string = (char *) malloc (sizeof(*s1) * (end - start + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (start < end)
		string[i++] = s1[start++];
	string[i] = 0;
	return (string);
}
