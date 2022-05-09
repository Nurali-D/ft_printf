/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 02:55:59 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/29 17:19:34 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_intlen(int64_t num)
{
	int			i;

	i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char		*ft_wrnum(char *b, int64_t c)
{
	int			i;

	if (c < 0 && (i = ft_intlen(c)) > 0)
	{
		b[0] = '-';
		c *= -1;
		b[i + 1] = '\0';
		while (c)
		{
			b[i] = c % 10 + '0';
			c /= 10;
			i--;
		}
	}
	else if ((i = ft_intlen(c)) > 0)
	{
		b[i] = '\0';
		while (c)
		{
			b[i - 1] = c % 10 + '0';
			c /= 10;
			i--;
		}
	}
	return (b);
}

char			*ft_itoa_mod(int64_t n)
{
	char		*ret;
	int64_t		nl;

	if (!(ret = (char*)malloc((ft_intlen(n) + 2) * sizeof(char))))
		return (NULL);
	if (n == INT64_MIN)
	{
		ret = ft_memcpy(ret, "-9223372036854775808", 20);
		ret[21] = '\0';
	}
	nl = n;
	if (n == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	return (ft_wrnum(ret, nl));
}
