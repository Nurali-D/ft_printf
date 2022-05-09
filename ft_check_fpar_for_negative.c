/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fpar_for_negative.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:15:09 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/26 04:15:14 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_fpar_for_negative(t_spf *fpar)
{
	if (fpar->wdh < 0)
	{
		fpar->flag |= F_MINUS;
		fpar->wdh *= -1;
	}
	if (fpar->prec_mod < 0)
		fpar->flag -= P_DOT;
}
