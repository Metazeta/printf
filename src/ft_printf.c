/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 13:54:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 12:24:14 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			putnstr(const char *str, int beg, int end)
{
	write(1, str + beg, end - beg);
	return (end - beg);
}

int			getprct(char *str, int p)
{
	while (str[p] && str[p] != '%')
		p++;
	return (p);
}

int			checkformat(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		i = getprct(format, i);
		if (format[i])
		{
			i++;
			while (format[i] && isopt(format[i]))
				i++;
			if (!istag(format[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;

	g_put = 0;
	if (!checkformat((char *)format))
		return (0);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		g_put += putnstr(format, i, getprct((char*)format, i));
		i = getprct((char*)format, i);
		if (format[i])
			launch(args, (char*)(format + i));
		i += format_len((char*)format + i);
	}
	va_end(args);
	return (g_put);
}
