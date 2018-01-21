/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_pc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 18:57:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 18:34:02 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			prf_pc(char *str, char *opt)
{
	int		sp;
	int		i;

	(void)str;
	if ((sp = hdlspaces(opt)) > 0)
		putnchar(sp - 1, ' ');
	i = 1;
	while (opt[i] && opt[i] != '%')
		i++;
	if (opt[i] == '%')
		write(1, "%", 1);
	if ((sp = hdlspaces(opt)) < 0)
	{
		sp = -sp;
		putnchar(sp - 1, ' ');
	}
	return (opt[i] == '%' && sp <= 1 ? 1 : 0);
}
