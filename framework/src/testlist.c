/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testlist.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 13:51:48 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/03 22:38:28 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"

static t_unit_test	*new_unit_test(char *print, int (*f)(void))
{
	t_unit_test	*test;

	if (!print || !f)
		return (NULL);
	test = malloc(sizeof(t_unit_test));
	if (!test)
		return (NULL);
	test->print = print;
	test->func = f;
	test->next = NULL;
	return (test);
}

void				load_test(t_unit_test **tstst, char *print, int (*f)(void))
{
	t_unit_test *test;
	t_unit_test *iterator;

	test = new_unit_test(print, f);
	if (!test)
		return ;
	if (!(*tstst))
	{
		*tstst = test;
		return ;
	}
	iterator = *tstst;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = test;
}

int					run_test(t_unit_test *test)
{
	pid_t	id;
	int		res;
	int		status;

	res = 0;
	id = fork();
	if (id == -1)
		return (-1);
	if (id == 0)
	{
		exit(test->func());
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			res = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			res = WTERMSIG(status);
	}
	return (res);
}

/*
 ** Run each test in a new process.
*/

int					launch_tests(t_unit_test **testlist)
{
	t_unit_test	*iterator;
	int			nb_success;
	int			nb_tests;
	int			result;

	nb_tests = 0;
	nb_success = 0;
	if (!*testlist)
		return (-1);
	iterator = *testlist;
	while (iterator)
	{
		if ((result = run_test(iterator)) == 0)
			nb_success++;
		to_error(iterator->print, result);
		nb_tests++;
		iterator = iterator->next;
	}
	ft_putnbr_fdfw(nb_success, 1);
	ft_putstrfw("/");
	ft_putnbr_fdfw(nb_tests, 1);
	ft_putstrfw(" tests checked\n");
	return (nb_success);
}
