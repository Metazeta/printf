/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:01:37 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 18:17:07 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

void		ft_putstri(unsigned int *str);
void		ft_putwstr(wchar_t *str);
void		ft_putwchar(wchar_t c);
void		ft_putchar(int c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
int			ft_printf(const char *format, ...);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t len);
void		*ft_memalloc(size_t len);
char		*ft_strnew(size_t size);

#endif
