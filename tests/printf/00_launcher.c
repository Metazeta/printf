/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   00_launcher.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 11:48:51 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:10:32 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int		prf_launcher(void)
{
	t_unit_test		*testlist;

	testlist = NULL;
	ft_putendl("====> PRINTF UNIT CHECKER");
	load_test(&testlist, "Basic test 1", &prf_test_01);
	load_test(&testlist, "Basic test 2", &prf_test_02);
	load_test(&testlist, "Moulitest 1", &prf_test_03);
	/*load_test(&testlist, "Test 4", &prf_test_04);*/
	/*load_test(&testlist, "Test 5", &prf_test_05);*/
	return (launch_tests(&testlist));
}
