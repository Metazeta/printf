/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_d.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 18:24:55 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 16:26:12 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	d_res_len(intmax_t value)
{
	int				len;
	uintmax_t		nb;

	len = 0;
	if (value < 0)
	{
		nb = -value;
		len++;
	}
	else
		nb = value;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	if (value == 0)
		len = 1;
	return (len);
}

char			*ft_prf_itoa(intmax_t value, int zeros)
{
	char			*str;
	int				len;
	int				i;
	intmax_t		nb;

	len = d_res_len(value) + zeros;
	nb = value < 0 ? -value : value;
	str = ft_prf_strnew(len + 1);
	str[0] = value < 0 ? '-' : '0';
	i = value < 0;
	while (i <= zeros + (value < 0))
	{
		str[i] = '0';
		i++;
	}
	i = 0;
	while (i < len - (value < 0) - zeros)
	{
		str[len - i - 1] = '0' + nb % 10;
		nb /= 10;
		i++;
	}
	str[len] = 0;
	return (str);
}

int				hdlprec(intmax_t nb, char *opt)
{
	int		zeros;
	int		i;

	i = 0;
	if (opt[1] == '0')
		return (ft_prf_atoi(opt + 1) - d_res_len(nb));
	while (opt[i] && opt[i] != '.')
		i++;
	if (!opt[i])
		return (0);
	zeros = ft_prf_atoi(opt + i + 1) - d_res_len(nb);
	return (zeros < 0 ? 0 : zeros + (nb < 0));
}

int				prf_d_type(intmax_t nb, char *opt)
{
	unsigned int	sp;
	unsigned int	len;
	unsigned int	printed;

	if ((sp = hdlspaces(opt)) > 0 && opt[1] != '0')
		putnchar(sp - d_res_len(nb), ' ');
	printed = 0;
	if (contains(opt, ' ') && !sp)
		printed += putnchar(1, ' ');
	if (contains(opt, '+') && nb >= 0)
		printed = putnchar(1, '+');
	printed += hdlprec(nb, opt);
	len = d_res_len(nb);
	write(1, ft_prf_itoa(nb, hdlprec(nb, opt)), len + hdlprec(nb, opt));
	printed += len;
	if (hdlspaces(opt) < 0)
	{
		sp = -sp;
		putnchar(sp - d_res_len(nb), opt[1] != '0' ? ' ' : '0');
	}
	return ((sp <= printed) ? printed : sp);
}

int				prf_d(va_list args, char *opt)
{
	char	type;
	char	tag;

	tag = istag(opt[format_len(opt) - 1]);
	type = get_type(opt);
	if (type == 'j')
		return (prf_d_type(va_arg(args, intmax_t), opt));
	else if (type == 'k')
		return (prf_d_type((intmax_t)(long long)va_arg(args, long long), opt));
	else if (tag == 'D' || type == 'l')
		return (prf_d_type((intmax_t)(long)va_arg(args, long), opt));
	else if (tag == 'u')
		return (prf_d_type((intmax_t)(unsigned int)va_arg(args, unsigned int)
		, opt));
	else
		return (prf_d_type((intmax_t)(int)va_arg(args, int), opt));
}
