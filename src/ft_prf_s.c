/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 17:11:07 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:20:55 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			prf_s(char *str, const t_format *opt)
{
	(void)opt;
	if (!str)
		return (write(1, "(null)", 6) ? 6 : 0);
	else
		write(1, str, ft_prf_strlen(str));
	return (ft_prf_strlen(str));
}
