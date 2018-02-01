/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:01:37 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 13:08:01 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_format
{
		char	*flags;
		int		width;
		int		prec;
		char	type;
		char	tag;
}				t_format;

char			*ft_prf_strsub(char const *s, unsigned int start, size_t len);
unsigned int	d_res_len(intmax_t value);
void			scan_format(t_format **form, char *opt);
int				contains(char *str, char c);
int				getprct(char *str, int p);
char			get_type(char *opt);
unsigned int	ft_prf_abs(int n);
char			isopt(char c);
char			istag(char c);
char			isflag(char c);
void			ft_putstri(unsigned int *c);
int				max(int a, int b);
char			*prf_strofchar(const char c, int nb);
char			*ft_prf_strjoin(char const *s1, char const *s2);
int				putnchar(int nb, char c);
int				isnum(char c);
size_t			bitlen(unsigned int value);
size_t			get_nbytes(wchar_t c);
int				prf_u_type(uintmax_t nb, const t_format *opt);
char			*ft_prf_itoa_base(uintmax_t value, int base, int maj);
int				ft_prf_atoi(char *str);
unsigned int	res_len(uintmax_t value, int base);
char			to_char(uintmax_t val, int maj);
int				prf_c(va_list args, const t_format *opt);
int				prf_p(void *ptr, const t_format *opt);
int				prf_d(va_list args, const t_format *opt);
int				prf_pc(char *str, const t_format *opt);
int				prf_s(char *str, const t_format *opt);
int				prf_x(va_list args, const t_format *opt);
int				prf_o(va_list args, const t_format *opt);
int				putnstr(const char *str, int beg, int end);
size_t			format_len(char *prct);
int				launch(va_list args, const t_format *formati);
void			ft_putstri(unsigned int *str);
void			ft_putwstr(wchar_t *str);
int				ft_putwchar(wchar_t c);
void			ft_putchar(int c);
char			*ft_prf_strnew(size_t size);
size_t			ft_prf_strlen(const char *str);
void			*ft_prf_memalloc(size_t len);
int				ft_printf(const char *format, ...);

#endif
