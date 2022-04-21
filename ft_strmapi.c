/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:40:49 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:35:16 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			length;
	char			*rest;

	if (!s || !f)
		return (NULL);
	i = 0;
	rest = NULL;
	length = ft_strlen(s);
	rest = (char *)ft_calloc(sizeof(char), length + 1);
	if (rest != NULL)
	{
		while (s[i])
		{
			rest[i] = f(i, s[i]);
			i++;
		}
		rest[i] = '\0';
	}
	return (rest);
}
