/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:15:23 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 13:18:36 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_flag(t_spf *fpar, char *str)
{
	if (*str == '-')
		fpar->flag |= F_MINUS;
	if (*str == '+')
		fpar->flag |= F_PLUS;
	if (*str == ' ')
		fpar->flag |= F_SPACE;
	if (*str == '#')
		fpar->flag |= F_HASH;
	if (*str == '0')
		fpar->flag |= F_ZERO;
	str++;
	if (*str == '-' || *str == '+' || *str == ' ' || *str == '#'
	|| *str == '0')
		str = ft_get_flag(fpar, str);
	return (str);
}

char	*ft_get_width(va_list vlin, t_spf *fpar, char *str)
{
	char	*width;
	int		i;

	if (!(i = 0) && *str == '*')
	{
		fpar->wdh = va_arg(vlin, int);
		str++;
		return (str);
	}
	while (str[i++] != '.' && ft_isdigit(str[i]))
		;
	if (!(width = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*str != '.' && ft_isdigit(*str))
	{
		width[i] = *str++;
		i++;
	}
	width[i] = '\0';
	fpar->wdh = ft_atoi(width);
	free(width);
	width = NULL;
	return (str);
}

char	*ft_get_prec(va_list vlin, t_spf *fpar, char *str)
{
	char	*prec;
	int		i;

	fpar->flag |= P_DOT;
	if (!(i = 0) && *(++str) == '*')
	{
		fpar->prec_mod = va_arg(vlin, int);
		str++;
		return (str);
	}
	while (ft_isdigit(str[i++]))
		;
	if (!(prec = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (ft_isdigit(*str))
	{
		prec[i] = *str++;
		i++;
	}
	prec[i] = '\0';
	fpar->prec_mod = ft_atoi(prec);
	free(prec);
	prec = NULL;
	return (str);
}

char	*ft_get_len_mod(t_spf *fpar, char *str)
{
	if (*str == 'l' && *(str + 1) == 'l')
		fpar->len_mod |= L_LL;
	else if (*str == 'l')
		fpar->len_mod |= L_L;
	if (*str == 'h' && *(str + 1) == 'h')
		fpar->len_mod |= L_HH;
	else if (*str == 'h')
		fpar->len_mod |= L_H;
	if (fpar->len_mod == L_L || fpar->len_mod == L_H)
		return (str + 1);
	return (str + 2);
}

char	*ft_get_type(t_spf *fpar, char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
	|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%'
	|| *str == 'n' || *str == 'f' || *str == 'g' || *str == 'e')
	{
		fpar->type_spec = *str;
		return (++str);
	}
	return (NULL);
}
