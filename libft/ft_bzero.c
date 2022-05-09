/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:50:51 by ltulune           #+#    #+#             */
/*   Updated: 2020/10/31 23:27:32 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buf;

	if (!s && !n)
		return ;
	buf = (unsigned char*)s;
	while (n)
	{
		*buf = 0;
		buf++;
		n--;
	}
}
