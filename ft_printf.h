/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:30:02 by omotyliu          #+#    #+#             */
/*   Updated: 2017/02/12 18:30:03 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include "libft/libft.h"
# include <wchar.h>
# include <limits.h>

typedef struct			s_type
{
	char			*flags;
	int				width;
	int				prec;
	char			*size;
	char			*arg;
	char			type;
	long long int	num;
	int				base;
	int				minus;
}						t_type;

void					print_str(t_type *cons);
int						ft_printf(const char *restrict format, ...);
int						get_spec(char ch);
char					get_spec_init(char ch);
int						get_flag(char ch);
int						get_size(char ch);
int						size_cmp(char *temp, char *cons);
int						parse_arg(t_type *cons, va_list list, char *temp);
void					print_ch(char *temp, int *i);
int						parse_wildcard(char *str, t_type *cons, va_list list);
int						if_snumber(t_type *cons, va_list list);
int						if_unumber(t_type *cons, va_list list);
char					*itoa_base(unsigned long long int num, int base);
void					build_arg_num(t_type *cons);
void					parse_const(const char *str, t_type *cons,
						va_list list);
int						if_string(t_type *cons, va_list list);
int						if_number(t_type *cons, va_list list);
int						if_char(t_type *cons, va_list list);
int						is_unsigned(t_type *cons);
int						is_flag(char ch);
char					*to_bighex(char *width, t_type *cons);
void					check_null(long long int temp, t_type *cons);
int						parse_wdth_s(t_type *cons, va_list list);
void					parse_base(const char *str, t_type *cons);
void					build_arg_char(t_type *cons);
char					*to_char(wchar_t *str);

#endif
