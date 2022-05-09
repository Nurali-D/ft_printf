/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:15:34 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/29 17:20:56 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_to_str(char *s, int b)
{
	static int		i;
	char			*tmp;

	if (b >= 0 && b <= 9)
	{
		tmp = ft_itoa(b);
		s[i] = tmp[0];
		free(tmp);
	}
	if (b == 10)
		s[i] = 'a';
	if (b == 11)
		s[i] = 'b';
	if (b == 12)
		s[i] = 'c';
	if (b == 13)
		s[i] = 'd';
	if (b == 14)
		s[i] = 'e';
	if (b == 15)
		s[i] = 'f';
	i++;
	if (i == 16)
		i = 0;
}

char	*ft_to_up(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

char	*int_to_hex(unsigned long long int a, int type)
{
	unsigned long long int	mask;
	int						i;
	int						buf;
	char					*str;

	buf = 0;
	i = 1;
	str = (char *)malloc(sizeof(char) * 17);
	mask = 1ULL << 63;
	while (i <= 64)
	{
		if ((a & mask))
			buf |= 1;
		a <<= 1;
		if (i++ % 4 == 0)
		{
			save_to_str(str, buf);
			buf = 0;
		}
		buf <<= 1;
	}
	str[16] = '\0';
	if (type == 'X')
		str = ft_to_up(str);
	return (str);
}
