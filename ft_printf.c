/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:13:06 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 13:02:13 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	init(t_spf *fp)
{
	fp->flag = 0;
	fp->wdh = 0;
	fp->prec_mod = 0;
	fp->len_mod = 0;
	fp->type_spec = 0;
}

char	*get_specificator(va_list vlin, char *str, t_spf *fpar)
{
	str++;
	while (!(fpar->type_spec))
	{
		if (*str == '-' || *str == '+' || *str == ' ' || *str == '#'
		|| *str == '0')
			str = ft_get_flag(fpar, str);
		else if (*str == '*' || (ft_isdigit(*str)))
			str = ft_get_width(vlin, fpar, str);
		else if (*str == '.')
			str = ft_get_prec(vlin, fpar, str);
		else if (*str == 'l' || *str == 'h')
			str = ft_get_len_mod(fpar, str);
		else if (!(str = ft_get_type(fpar, str)))
			return (NULL);
	}
	return (str);
}

int		ft_print_spec_arg(va_list vlin, t_spf *fp)
{
	int	i;

	i = 0;
	if (fp->type_spec == 'c')
		i = ft_print_c(va_arg(vlin, int), fp);
	if (fp->type_spec == 's')
		i = ft_print_s(va_arg(vlin, char*), fp);
	if (fp->type_spec == 'p')
		i = ft_print_p(va_arg(vlin, unsigned long long), fp);
	if (fp->type_spec == 'd' || fp->type_spec == 'i')
		i = ft_print_di(ft_conv_di(vlin, fp), fp);
	if (fp->type_spec == 'u')
		i = ft_print_u(ft_converter_ux(vlin, fp), fp);
	if (fp->type_spec == 'x' || fp->type_spec == 'X')
		i = ft_print_x(ft_converter_ux(vlin, fp), fp);
	if (fp->type_spec == '%')
		i = ft_print_percent(fp);
	return (i);
}

int		ft_parser(va_list vlin, t_spf *fpar, char *str)
{
	int	ret_len;

	ret_len = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			ret_len++;
			str++;
		}
		else
		{
			init(fpar);
			if (!(str = get_specificator(vlin, str, fpar)))
			{
				fpar->type_spec = -1;
				return (ret_len);
			}
			check_fpar_for_negative(fpar);
			ret_len += ft_print_spec_arg(vlin, fpar);
		}
	}
	return (ret_len);
}

int		ft_printf(const char *f_str, ...)
{
	va_list	vlin;
	t_spf	*fpar;
	int		return_len;

	return_len = 0;
	if (!(fpar = (t_spf *)malloc(sizeof(t_spf))))
		return (-1);
	init(fpar);
	va_start(vlin, f_str);
	return_len = ft_parser(vlin, fpar, (char *)f_str);
	if (fpar->type_spec == -1)
		write(1, "\nwarning: incomplete format specifier", 37);
	else if (fpar->type_spec == -2)
		write(1, "\nwarning: malloc error", 22);
	va_end(vlin);
	free(fpar);
	return (return_len);
}
