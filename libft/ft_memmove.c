/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-sofy <hes-sofy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:56:25 by hes-sofy          #+#    #+#             */
/*   Updated: 2026/10/31 16:40:14 by hes-sofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ds;
	const char	*sr;

	if (dest == src)
		return (dest);
	ds = dest;
	sr = src;
	if (ds > sr)
	{
		ds += n;
		sr += n;
		while (n--)
			*--ds = *--sr;
	}
	else
	{
		while (n--)
			*ds++ = *sr++;
	}
	return (dest);
}
