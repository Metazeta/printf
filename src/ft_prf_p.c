/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 18:53:57 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				prf_p(void *ptr, char *opt)
{
	unsigned int	sp;
	unsigned int	len;

	if ((sp = hdlspaces(opt)) > 0)
		putnchar(sp - 14,
		opt[1] != '0' ? ' ' : '0');
	len = 14;
	sp += putnstr("0x", 0, 2);
	write(1, ft_prf_itoa_base((uintmax_t)ptr, 16, 0), len);
	if (hdlspaces(opt) < 0)
	{
		sp = -sp;
		putnchar(sp - 10,
		opt[1] != '0' ? ' ' : '0');
	}
	if (!ptr)
		return (3);
	return (sp <= 14 ? 14 : sp - 2);
}
