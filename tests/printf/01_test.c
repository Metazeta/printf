/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   01_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 19:25:23 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:58:13 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int				prf_test_01(void)
{
	int		ok;
	int old_stdout;
	char	*str;
	int		ret;

	ret = ft_printf((void *)(str = "Test vide"));
	printf("valeur de retour : %d\n", ret);
	return(ok == 0 ? 0 : -1);
}
