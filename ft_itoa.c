/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:16:14 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/13 23:08:40 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_nb_digit(long n_l, int sign)
{
	unsigned int	num_dg;

	if (n_l == 0)
		return (1);
	num_dg = 0;
	while (n_l > 0)
	{
		n_l /= 10;
		num_dg++;
	}
	if (sign == -1)
		num_dg++;
	return (num_dg);
}

static void	convert_num(char *outstr, long n_l, unsigned int num_dg, int sign)
{
	outstr[num_dg] = '\0';
	outstr[--num_dg] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		outstr[--num_dg] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		outstr[0] = '-';
}

char	*ft_itoa(int n)
{
	char			*outstr;
	long			n_l;
	unsigned int	num_dg;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		n_l = (long)n * -1;
		sign = -1;
	}
	else
		n_l = n;
	num_dg = get_nb_digit(n_l, sign);
	outstr = malloc(sizeof(char) * (num_dg + 1));
	if (! outstr)
		return (NULL);
	convert_num(outstr, n_l, num_dg, sign);
	return (outstr);
}
