/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:42:49 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 13:36:13 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return (b);
}

static void		ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}

void			*ft_prf_memalloc(size_t len)
{
	void	*mem;

	if (!(mem = (void *)malloc(len)))
		return (NULL);
	ft_bzero(mem, len);
	return (mem);
}

int				putnchar(int nb, char c)
{
	int		i;

	i = nb;
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
	return (nb);
}
