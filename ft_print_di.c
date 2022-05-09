/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:51:14 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 11:02:31 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int64_t n, t_spf *fp)
{
	char	*num;
	char	*sign;
	int		i;

	i = 0;
	sign = NULL;
	if (!(num = ft_itoa_mod(n)))
		return (change_type_error(fp));
	if (n < 0)
	{
		sign = "-";
		num = ft_memmove(num, &num[1], ft_strlen(num));
	}
	else if (n >= 0 && (fp->flag & F_PLUS))
		sign = "+";
	i = ft_print_pidux(num, fp, sign);
	free(num);
	num = NULL;
	return (i);
}
