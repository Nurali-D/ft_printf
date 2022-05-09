/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:59:18 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 08:43:44 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_adress_for_zero(unsigned long long adr, char *str)
{
	int	i;

	i = 0;
	if (adr != 0)
	{
		while (str[i] == '0')
			i++;
		ft_memmove(str, &str[i], ft_strlen(str) - i + 1);
	}
	else
		str[1] = '\0';
	return (str);
}

int		ft_print_p(unsigned long long adress, t_spf *fp)
{
	char	*str;
	char	*sign;
	int		i;

	sign = NULL;
	if (!(i = 0) && adress == 0 && adress == (unsigned long long)NULL
	&& fp->type_spec == 'p')
	{
		sign = "0x";
		i = ft_print_pidux("0", fp, sign);
		return (i);
	}
	else if (!(str = int_to_hex(adress, fp->type_spec)))
		return (change_type_error(fp));
	str = check_adress_for_zero(adress, str);
	if (fp->type_spec == 'p' || (fp->type_spec == 'x' && (fp->flag & F_HASH)))
		sign = "0x";
	else if (fp->type_spec == 'X' && (fp->flag & F_HASH))
		sign = "0X";
	i = ft_print_pidux(str, fp, sign);
	free(str);
	return (i);
}
