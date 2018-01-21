/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:01:37 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 14:04:18 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int				g_put;
int				contains(char *str, char c);
char			get_type(char *opt);
unsigned int	ft_prf_abs(int n);
char			isopt(char c);
char			istag(char c);
int				putnchar(int nb, char c);
int				hdlspaces(char *opt);
int				isnum(char c);
char			*ft_prf_itoa_base(uintmax_t value, int base, int maj);
int				ft_prf_atoi(char *str);
unsigned int	res_len(uintmax_t value, int base);
int				prf_p(void *ptr, char *opt);
int				prf_d(va_list args, char *opt);
int				prf_pc(char *str, char *opt);
int				prf_s(char *str, char *opt);
int				prf_x(uintmax_t nb, char *opt);
int				putnstr(const char *str, int beg, int end);
size_t			format_len(char *prct);
void			launch(va_list args, char *formati);
void			ft_putstri(unsigned int *str);
void			ft_putwstr(wchar_t *str);
void			ft_putwchar(wchar_t c);
void			ft_putchar(int c);
char			*ft_prf_strnew(size_t size);
size_t			ft_prf_strlen(const char *str);
void			*ft_prf_memalloc(size_t len);
int				ft_printf(const char *format, ...);

#endif
