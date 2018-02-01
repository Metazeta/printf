/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_launcher.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 20:22:12 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 11:08:03 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			launch(va_list args, const t_format *format)
{
	char		tag;
	int			ret;

	ret = 0;
	tag = format->tag;
	if (tag == 'd' || tag == 'D' || tag == 'i' || tag == 'u' || tag == 'U')
		ret = prf_d(args, format);
	else if (tag == 'p')
		ret = prf_p(va_arg(args, void *), format);
	else if (tag == 's')
		ret = prf_s(va_arg(args, char *), format);
	else if (tag == 'c' || tag == 'C')
		ret = prf_c(args, format);
	else if (tag == '%')
		ret = prf_pc(va_arg(args, char *), format);
	else if (tag == 'x' || tag == 'X')
		ret = prf_x(args, format);
	else if (tag == 'O' || tag == 'o')
		ret = prf_o(args, format);
	return (ret);
}
