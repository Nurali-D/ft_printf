/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 04:38:40 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/29 16:03:42 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int h, t_spf *fp)
{
	int	i;

	i = ft_print_p((unsigned long long)h, fp);
	return (i);
}
