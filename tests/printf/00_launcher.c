/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   00_launcher.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 11:48:51 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:38:09 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int		prf_launcher(void)
{
	t_unit_test		*testlist;

	testlist = NULL;
	ft_putendl("====> PRINTF UNIT CHECKER");
	load_test(&testlist, "Test 1", &prf_test_01);
	/*load_test(&testlist, "Test 2", &ptr_test_02);*/
	/*load_test(&testlist, "Test 3", &ptr_test_03);*/
	/*load_test(&testlist, "Test 4", &ptr_test_04);*/
	/*load_test(&testlist, "Test 5", &ptr_test_05);*/
	return (launch_tests(&testlist));
}

