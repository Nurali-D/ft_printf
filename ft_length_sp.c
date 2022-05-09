/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:55:38 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 10:56:38 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		ft_conv_di(va_list vlin, t_spf *fp)
{
	int64_t buf;

	if ((fp->len_mod & L_H))
		buf = (short int)va_arg(vlin, int);
	else if ((fp->len_mod & L_HH))
		buf = (signed char)va_arg(vlin, int);
	else if ((fp->len_mod & L_L))
		buf = va_arg(vlin, long int);
	else if ((fp->len_mod & L_LL))
		buf = va_arg(vlin, long long int);
	else
		buf = va_arg(vlin, int);
	return (buf);
}

uint64_t	ft_converter_ux(va_list vlin, t_spf *fp)
{
	uint64_t buf;

	if ((fp->len_mod & L_H))
		buf = (unsigned short int)va_arg(vlin, unsigned int);
	else if ((fp->len_mod & L_HH))
		buf = (unsigned char)va_arg(vlin, unsigned int);
	else if ((fp->len_mod & L_L))
		buf = va_arg(vlin, unsigned long int);
	else if ((fp->len_mod & L_LL))
		buf = va_arg(vlin, unsigned long long int);
	else
		buf = va_arg(vlin, unsigned int);
	return (buf);
}
