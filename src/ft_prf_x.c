/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_x.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 15:25:49 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				hash(char *opt)
{
	int		i;

	i = 1;
	while (opt[i] && !istag(opt[i])
			&& opt[i] != '#')
		i++;
	return (opt[i] == '#');
}

int				prf_x_type(uintmax_t nb, char *opt)
{
	unsigned int	sp;
	int				maj;
	unsigned int	len;

	if ((sp = hdlspaces(opt)) > 0)
		putnchar(sp - res_len(nb, 16) - 2 * (nb && hash(opt)),
		opt[1] != '0' ? ' ' : '0');
	maj = istag(opt[format_len(opt) - 1]) == 'X' ? 1 : 0;
	len = res_len(nb, 16) > 0 ? res_len(nb, 16) : 1;
	sp = nb && hash(opt) && !maj ? sp + putnstr("0x", 0, 2) : sp;
	sp = nb && hash(opt) && maj ? sp + putnstr("0X", 0, 2) : sp;
	write(1, ft_prf_itoa_base(nb, 16, maj), len);
	if (hdlspaces(opt) < 0)
	{
		sp = -sp;
		putnchar(sp - res_len(nb, 16) - 2 * (nb && hash(opt)),
		opt[1] != '0' ? ' ' : '0');
	}
	return (sp <= (res_len(nb, 16) + 2 * (nb && hash(opt)))
			? res_len(nb, 16) + 2 * (nb && hash(opt)) :
			sp - 2 * (nb && hash(opt)));
}

char			get_type(char *opt)
{
	int		i;

	i = 1;
	while (!istag(opt[i]) &&
			opt[i] != 'j' &&
			opt[i] != 'l' &&
			opt[i] != 'u')
		i++;
	if (opt[i] == 'l' && opt[i + 1] == 'l')
		return ('k');
	else if (opt[i])
		return (opt[i]);
	return (0);
}

int				prf_x(uintmax_t nb, char *opt)
{
	char	type;

	type = get_type(opt);
	if (type == 'j')
		return (prf_x_type(nb, opt));
	else if (type == 'k')
		return (prf_x_type((uintmax_t)(long long)nb, opt));
	else if (type == 'l')
		return (prf_x_type((uintmax_t)(long)nb, opt));
	else
		return (prf_x_type((uintmax_t)(unsigned int)nb, opt));
}
