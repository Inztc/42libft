/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:17:59 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:37:57 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	const char		*n;
	const char		*h;

	if (!*needle)
		return ((char *)haystack);
	j = 0;
	while (haystack[j] != '\0' && (size_t)j < len)
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			h = haystack;
			n = needle;
			while (n[i] != '\0' && h[i + j] == n[i] && (size_t)(j + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char *)&haystack[j]);
		}
		++j;
	}
	return (0);
}
