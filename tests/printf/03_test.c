/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   03_test.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 19:25:23 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:00:26 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"

int				prf_test_03(void)
{
	int		ok;
	int old_stdout;
	int		fd;
	char	buf[23];

	old_stdout = dup(1);
	freopen("printf/out/test01.out","w", stdout);
	ft_putstr("This is a simple test.");
	dup2(old_stdout, fileno(stdout));
	close(old_stdout);
	fd = open("printf/out/test01.out", O_RDONLY);
	read(fd, buf, 22);
	buf[22] = 0;
	ok = strcmp(buf, "This is a simple test.");
	close(fd);
	return(ok == 0 ? 0 : -1);
}
