/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:11:23 by btiewcha          #+#    #+#             */
/*   Updated: 2022/04/21 15:54:38 by btiewcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*meh;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	meh = malloc(count * size);
	if (meh == NULL)
		return (NULL);
	ft_bzero(meh, count * size);
	return (meh);
}
