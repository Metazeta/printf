/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 14:20:42 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 12:30:50 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libunit.h"

void	ft_putstrfw(char *str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void		to_error(char *print, int err)
{
	ft_putstrfw("--> ");
	ft_putstrfw(print);
	ft_putstrfw(": ");
	if (err == SIGSEGV)
		ft_putstrfw("SEGV");
	else if (err == SIGABRT)
		ft_putstrfw("ABRT");
	else if (err == SIGBUS)
		ft_putstrfw("BUSE");
	else if (err == 0)
		ft_putstrfw("OK");
	else if (err == 255)
		ft_putstrfw("KO");
	ft_putstrfw("\n");
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fdfw(int n, int fd)
{
	unsigned int n1;

	n1 = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = -n1;
	}
	if (n1 < 10)
		ft_putchar_fd(n1 + '0', fd);
	else
	{
		ft_putnbr_fdfw(n1 / 10, fd);
		ft_putnbr_fdfw(n1 % 10, fd);
	}
}

void	display_resume(int nb_tests, int nb_success)
{
	ft_putstrfw("--RESUME--\n");
	ft_putnbr_fdfw(nb_success, 1);
	ft_putstrfw("/");
	ft_putnbr_fdfw(nb_tests, 1);
	ft_putstrfw("\n");
}
