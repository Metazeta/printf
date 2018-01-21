/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libunit.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 12:36:58 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/03 22:52:35 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct				s_unit_test
{
	char					*print;
	int						(*func)(void);
	struct s_unit_test		*next;
}							t_unit_test;

void						load_test(t_unit_test **t, char *p, int (*f)(void));
int							launch_tests(t_unit_test **testlist);
void						ft_putstrfw(char *str);
void						to_error(char *print, int err);
void						ft_putnbr_fdfw(int n, int fd);
void						display_resume(int nb_tests, int nb_success);
#endif
