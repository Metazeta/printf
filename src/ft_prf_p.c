/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:21:00 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				prf_p(void *ptr, const t_format *opt)
{
	unsigned int	sp;
	unsigned int	len;

	len = 14;
	sp = putnstr("0x", 0, 2);
	(void)opt;
	write(1, ft_prf_itoa_base((uintmax_t)ptr, 16, 0), len);
	if (!ptr)
		return (3);
	return (sp <= 14 ? 14 : sp - 2);
}
