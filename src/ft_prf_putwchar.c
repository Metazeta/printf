/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prf_putwchar.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:39:50 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 17:09:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	bitlen(unsigned int value)
{
	size_t		len;

	len = 0;
	while (value)
	{
		value = value >> 1;
		len++;
	}
	return (len);
}

void			fill_mask2(unsigned int input, int nbytes)
{
	unsigned int	res[4];

	if (nbytes <= 16)
	{
		res[0] = 0b11100000 | (input >> 12);
		res[1] = 0b10000000 | ((input >> 6) & 0b111111);
		res[2] = 0b10000000 | (input & 0b111111);
		res[3] = 0;
	}
	else
	{
		res[0] = 0b11110000 | (input >> 18);
		res[1] = 0b10000000 | ((input >> 12) & 0b111111);
		res[2] = 0b10000000 | ((input >> 6) & 0b111111);
		res[3] = 0b10000000 | ((input & 0b111111));
	}
	ft_putstri(res);
}

void			fill_mask(unsigned int input, int nbytes)
{
	unsigned int	res[4];

	if (nbytes <= 7)
	{
		res[0] = input;
		res[1] = 0;
		ft_putstri(res);
	}
	else if (nbytes <= 11)
	{
		res[0] = 0b11000000 | (input >> 6);
		res[1] = 0b10000000 | (input & 0b111111);
		res[2] = 0;
		ft_putstri(res);
	}
	else
		fill_mask2(input, nbytes);
}

void			ft_putwchar(wchar_t c)
{
	size_t		len;

	len = bitlen(c);
	fill_mask(c, len);
}

void			ft_putwstr(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		i++;
	}
}
