/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:09:31 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/20 23:02:17 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *c)
{
	int			i;
	long long	tt;
	int			kk;

	tt = 0;
	i = 0;
	kk = 1;
	while (c[i] && (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13)))
		i++;
	if (c[i] && (c[i] == '-' || c[i] == '+'))
	{
		if (c[i] == '-')
			kk *= -1;
		i++;
	}
	while (c[i] && c[i] >= '0' && c[i] <= '9')
	{
		tt = tt * 10 + (c[i] - 48);
		i++;
	}
	if (tt * kk > 2147483647)
		return (-1);
	else if (tt * kk < -2147483648)
		return (0);
	return (tt * kk);
}
