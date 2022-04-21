/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:20:49 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/21 13:10:46 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	else if (start > ft_strlen(s))
		len = 0;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	string = ft_memcpy(string, &s[start], len);
	string[len] = '\0';
	return (string);
}
