/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_launcher.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 20:22:12 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 16:20:34 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		istag(char c)
{
	return (c == 's' ||
			c == '%' ||
			c == 'x' ||
			c == 'X' ||
			c == 'd' ||
			c == 'D' ||
			c == 'i' ||
			c == 'u' ||
			c == 'p'
			? c : 0);
}

char		isopt(char c)
{
	return ((c <= '9' && c >= '0') ||
			c == '.' ||
			c == 'l' ||
			c == 'j' ||
			c == '+' ||
			c == '-' ||
			c == 'z' ||
			c == ' ' ||
			c == 'h'
			? c : 0);
}

int			hdlspaces(char *opt)
{
	int		beg;
	int		end;

	beg = 1;
	while (opt[beg] && !istag(opt[beg]) && !isnum(opt[beg]) && opt[beg] != '.')
		beg++;
	if (opt[beg] == '.')
		return (0);
	end = beg;
	while (opt[end] && isnum(opt[end]))
		end++;
	return (ft_prf_atoi(opt + beg));
}

size_t		format_len(char *prct)
{
	size_t		len;
	int			status;

	status = 0;
	if (prct[0] != '%')
		return (0);
	len = 1;
	while (prct[len] && (isopt(prct[len]) && !istag(prct[len])))
		len++;
	if (!istag(prct[len]))
		return (0);
	return (len + 1);
}

void		launch(va_list args, char *format)
{
	char		tag;

	tag = istag(format[format_len(format) - 1]);
	if (tag == 'd' || tag == 'D' || tag == 'i' || tag == 'u')
		g_put += prf_d(args, format);
	else if (tag == 'p')
		g_put += prf_p(va_arg(args, void *), format);
	else if (tag == 's')
		g_put += prf_s(va_arg(args, char *), format);
	else if (tag == '%')
		g_put += prf_pc(va_arg(args, char *), format);
	else if (tag == 'x' || tag == 'X')
		g_put += prf_x(va_arg(args, intmax_t), format);
}
