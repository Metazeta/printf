/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_x.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 18:40:01 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_prf_itoa_x(uintmax_t nb, int maj, int prec)
{
	char			*str;
	int				len;
	int				i;
	int				zeros;

	len = res_len(nb, 16);
	zeros = prec - len;
	i = 0;
	str = ft_prf_strnew(len + zeros);
	str[0] = '0';
	while (i < (zeros + !nb))
		str[i++] = '0';
	i = prec - 1;
	while (nb != 0)
	{
		str[i] = to_char(nb % 16, maj);
		nb /= 16;
		i--;
	}
	str[len + zeros] = 0;
	return (str);
}

int				subprf_x_type(uintmax_t nb, const t_format *opt, int prec,
				int spaces)
{
	int		printed;

	if (!contains(opt->flags, '-'))
		putnchar(spaces, ' ');
	putnchar((contains(opt->flags, '+')), '+');
	printed = ((contains(opt->flags, '+') && spaces <= 0));
	if (contains(opt->flags, '#') && nb != 0)
		printed += (opt->tag == 'X') ? write(1, "0X", 2) : write(1, "0x", 2);
	return (printed);
}

int				prf_x_type(uintmax_t nb, const t_format *opt)
{
	int		prec;
	int		printed;
	int		spaces;
	int		stop;

	stop = (opt->prec == -1 && !nb);
	prec = max(res_len(nb, 16), opt->prec) * !stop;
	if (contains(opt->flags, '0') && !(opt->prec))
		prec = max(opt->width, res_len(nb, 16)) - contains(opt->flags, ' ');
	spaces = (opt->width) - prec;
	if (contains(opt->flags, '#') && nb != 0)
		spaces -= 2;
	if (contains(opt->flags, '#') && nb != 0 && opt->width == prec)
		prec -= 2;
	printed = prec + spaces * (spaces > 0);
	spaces -= (contains(opt->flags, '+'));
	if (contains(opt->flags, ' ') && spaces <= 0
		&& !contains(opt->flags, '+'))
		printed += putnchar(1, ' ');
	printed += subprf_x_type(nb, opt, prec, spaces);
	if (!stop)
		write(1, ft_prf_itoa_x(nb, opt->tag == 'X', prec), prec);
	if (contains(opt->flags, '-'))
		putnchar(spaces, ' ');
	return (printed);
}

int				prf_x(va_list args, const t_format *opt)
{
	if (opt->type == 'j')
		return (prf_x_type(va_arg(args, uintmax_t), opt));
	else if (opt->type == 'h')
		return (prf_x_type((unsigned short)va_arg(args, int), opt));
	else if (opt->type == 'i')
		return (prf_x_type((unsigned char)va_arg(args, int), opt));
	else if (opt->type == 'k')
		return (prf_x_type((uintmax_t)va_arg(args, long long), opt));
	else if (opt->type == 'l')
		return (prf_x_type((uintmax_t)va_arg(args, long), opt));
	else if (opt->type == 'z')
		return (prf_x_type((uintmax_t)va_arg(args, unsigned long long), opt));
	else
		return (prf_x_type((uintmax_t)va_arg(args, unsigned int), opt));
}
