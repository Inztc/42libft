/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:31:45 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:45:08 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	place_number(const char *string, char c)
{
	size_t			i;
	size_t			pnum;

	i = 0;
	pnum = 0;
	while (string[i] != 0)
	{
		if (string[i] != c && string[i] != 0)
		{
			pnum++;
			while (string[i] != c && string[i] != 0)
				i++;
		}
		else if (string[i] != 0)
			i++;
	}
	return (pnum);
}

static void	copy_string(char *dst, char const *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = 0;
}

static void	*mem_out(char **d_mem, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(d_mem[i]);
		i++;
	}
	free(d_mem);
	return (NULL);
}

static void	spliting(char const *s, char c, char **string)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			string[k] = ((char *)malloc(sizeof(char) * (i - start + 1)));
			if (string[k] == 0)
			{
				mem_out(string, k);
				return ;
			}
			copy_string(string[k], s, start, i);
			k++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char		**string;
	size_t		n;

	if (!s)
		return (0);
	n = place_number(s, c);
	string = (char **)malloc(sizeof(char *) * (n + 1));
	if (string == 0)
		return (0);
	string[n] = 0;
	if (n == 0)
		return (string);
	spliting(s, c, string);
	return (string);
}
