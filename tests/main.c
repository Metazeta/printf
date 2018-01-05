/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:54:27 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:39:35 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int		test(t_unit_test **launchers)
{
	ft_putstr("============TESTS============\n");
	load_test(launchers, "", &prf_launcher);
	return (NUM_TEST);
}

int		main(int argc, char **argv)
{
	int				nb_success;
	t_unit_test		*launchers;
	int				nb_tests;

	(void)argv;
	launchers = NULL;
	nb_success = 0;
	if (argc != 1)
		return (0);
	nb_tests = test(&launchers);
	while (launchers)
	{
		nb_success += launchers->func();
		ft_putstr("\n");
		launchers = launchers->next;
	}
	display_resume(nb_tests, nb_success);
	return (0);
}
