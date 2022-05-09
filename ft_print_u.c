/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 04:08:02 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/29 17:19:02 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(int64_t n, t_spf *fp)
{
	int		i;

	i = 0;
	if (fp->flag & F_SPACE)
		fp->flag -= F_SPACE;
	if (fp->flag & F_PLUS)
		fp->flag -= F_PLUS;
	i += ft_print_di(n, fp);
	return (i);
}
