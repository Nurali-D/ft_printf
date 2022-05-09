/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:00:51 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 08:35:13 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_no_minus(char *s, t_spf *fpar, int i)
{
	if (fpar->prec_mod < (int)ft_strlen(s))
		s[fpar->prec_mod] = '\0';
	i += ft_wid(fpar->wdh - ft_strlen(s), 0, fpar->flag & F_ZERO);
	ft_putstr_fd(s, 1);
	i += ft_strlen(s);
	free(s);
	return (i);
}

int		ft_minus_dot(char *str, t_spf *fpar, int i)
{
	if (fpar->prec_mod < (int)ft_strlen(str))
		str[fpar->prec_mod] = '\0';
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	i += ft_wid(fpar->wdh - i, 0, 0);
	free(str);
	return (i);
}

int		change_type_error(t_spf *fp)
{
	fp->type_spec = -2;
	return (0);
}

int		ft_print_s(char *s, t_spf *fpar)
{
	int		i;
	char	*str;

	if (!(i = 0) && !s)
		s = "(null)";
	if (!(str = ft_strdup(s)))
		return (change_type_error(fpar));
	if ((fpar->flag & F_MINUS))
	{
		if ((fpar->flag & P_DOT))
			return (ft_minus_dot(str, fpar, i));
		ft_putstr_fd(str, 1);
		i = ft_strlen(str);
		i += ft_wid(fpar->wdh - i, 0, 0);
	}
	else if ((fpar->flag & P_DOT))
		return (ft_no_minus(str, fpar, i));
	else
	{
		i += ft_wid(fpar->wdh - ft_strlen(str), 0, fpar->flag & F_ZERO);
		ft_putstr_fd(str, 1);
		i += ft_strlen(str);
	}
	free(str);
	return (i);
}
