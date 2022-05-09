/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltulune <ltulune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:18:12 by ltulune           #+#    #+#             */
/*   Updated: 2020/12/30 08:42:42 by ltulune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "./libft/libft.h"

# define F_MINUS 2
# define F_PLUS 4
# define F_SPACE 8
# define F_HASH 16
# define F_ZERO 32
# define P_DOT 64
# define L_L 2
# define L_LL 4
# define L_H 8
# define L_HH 16

typedef struct	s_spf
{
	int	flag;
	int	wdh;
	int	prec_mod;
	int	len_mod;
	int	type_spec;
}				t_spf;

int				ft_printf(const char *f_str, ...);
char			*ft_get_flag(t_spf *fpar, char *str);
char			*ft_get_width(va_list vlin, t_spf *fpar, char *str);
char			*ft_get_prec(va_list vlin, t_spf *fpar, char *str);
char			*ft_get_len_mod(t_spf *fpar, char *str);
char			*ft_get_type(t_spf *fpar, char *str);
int				ft_print_c(char c, t_spf *fpar);
int				ft_wid(int width, int m, int z);
int				ft_print_s(char *s, t_spf *fpar);
void			check_fpar_for_negative(t_spf *fpar);
int				ft_print_percent(t_spf *fp);
char			*int_to_hex(unsigned long long int a, int type);
int				ft_print_p(unsigned long long adress, t_spf *fp);
int				ft_print_di(int64_t n, t_spf *fp);
char			*ft_itoa_mod(int64_t n);
int				ft_print_u(int64_t n, t_spf *fp);
int				ft_print_x(unsigned int h, t_spf *fp);
int				ft_print_pidux(char *s, t_spf *fp, char *sign);
int64_t			ft_conv_di(va_list vlin, t_spf *fp);
uint64_t		ft_converter_ux(va_list vlin, t_spf *fp);
char			*ft_converter_s(char *s, t_spf *fp);
int				change_type_error(t_spf *fp);

#endif
