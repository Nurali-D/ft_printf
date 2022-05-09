/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pidux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:15:51 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 11:15:29 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_space(t_spf *fp, char *sign)
{
	int	i;

	i = 0;
	if ((fp->flag & F_SPACE) && !((sign)
	&& sign[0] == '-') && !(fp->flag & F_PLUS))
		i += ft_putstr_fd(" ", 1);
	return (i);
}

int		ft_p_minus_dot(char *s, t_spf *fp, char *sign, int i)
{
	if ((fp->flag & P_DOT))
	{
		if ((int)ft_strlen(s) < fp->prec_mod)
		{
			i += check_for_space(fp, sign);
			i += ft_putstr_fd(sign, 1);
			i += ft_wid(fp->prec_mod - ft_strlen(s), 0, 1);
			i += ft_putstr_fd(s, 1);
			i += ft_wid(fp->wdh - i, 0, 0);
			return (i);
		}
		i += check_for_space(fp, sign);
		i += ft_putstr_fd(sign, 1);
		if (!(s[0] == '0' && fp->prec_mod == 0))
			i += ft_putstr_fd(s, 1);
		i += ft_wid(fp->wdh - i, 0, 0);
	}
	else
	{
		i += check_for_space(fp, sign);
		i += ft_putstr_fd(sign, 1);
		i += ft_putstr_fd(s, 1);
		i += ft_wid(fp->wdh - i, 0, 0);
	}
	return (i);
}

int		ft_p_nominus_dot(char *s, t_spf *fp, char *sign, int i)
{
	if ((int)ft_strlen(s) < fp->prec_mod)
	{
		i += ft_wid(fp->wdh - fp->prec_mod - ft_strlen(sign), 0, 0);
		i += ft_putstr_fd(sign, 1);
		i += ft_wid(fp->prec_mod - ft_strlen(s), 0, 1);
		i += ft_putstr_fd(s, 1);
	}
	else
	{
		if (!(s[0] == '0' && fp->prec_mod == 0))
			i += ft_wid(fp->wdh - ft_strlen(s) - ft_strlen(sign), 0, 0);
		else
			i += ft_wid(fp->wdh - ft_strlen(sign), 0, 0);
		i += ft_putstr_fd(sign, 1);
		if (!(s[0] == '0' && fp->prec_mod == 0))
			i += ft_putstr_fd(s, 1);
	}
	return (i);
}

int		ft_print_pidux(char *s, t_spf *fp, char *sign)
{
	int	i;

	(void)sign;
	i = 0;
	if (fp->flag & F_MINUS)
		return (ft_p_minus_dot(s, fp, sign, i));
	else if ((fp->flag & P_DOT))
		return (ft_p_nominus_dot(s, fp, sign, i));
	else if (fp->flag & F_ZERO)
	{
		i += ft_putstr_fd(sign, 1);
		i += ft_wid(fp->wdh - i - ft_strlen(s), 0, 1);
		i += ft_putstr_fd(s, 1);
	}
	else
	{
		i += check_for_space(fp, sign);
		i += ft_wid(fp->wdh - ft_strlen(sign) - ft_strlen(s), 0, 0);
		i += ft_putstr_fd(sign, 1);
		i += ft_putstr_fd(s, 1);
	}
	return (i);
}
