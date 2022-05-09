/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 04:26:46 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/29 11:39:25 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(char c, t_spf *fpar)
{
	int	i;

	i = 0;
	if ((fpar->flag & F_MINUS))
	{
		ft_putchar_fd(c, 1);
		if (fpar->flag & F_ZERO)
			fpar->flag -= F_ZERO;
	}
	i = ft_wid(fpar->wdh, 1, fpar->flag & F_ZERO);
	if (!(fpar->flag & F_MINUS))
		ft_putchar_fd(c, 1);
	return (i + 1);
}
