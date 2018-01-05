/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   01_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 19:25:23 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 15:40:26 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int				prf_test_01(void)
{
	int		ok;
	int old_stdout;
	int		fd;
	char	buf[3];

	old_stdout = dup(1);
	freopen("printf/out/test01.out","w", stdout);
	ft_putstr("ceci\nest\nun\ntest\nbasique");
	dup2(old_stdout, fileno(stdout));
	close(old_stdout);
	fd = open("printf/out/test01.out", O_RDONLY);
	read(fd, buf, 2);
	buf[2] = 0;
	ok = strcmp(buf, "ce");
	close(fd);
	return(ok == 0 ? 0 : -1);
}
