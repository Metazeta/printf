/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 13:54:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:54:19 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			putnstr(const char *str, int beg, int end)
{
	write(1, str + beg, end - beg);
	return (end - beg);
}

void		init_format(t_format **format)
{
	if (!(*format) && !(*format = (t_format*)malloc(sizeof(t_format))))
		return ;
	(*format)->flags = NULL;
	(*format)->width = 0;
	(*format)->prec = 0;
	(*format)->type = 0;
}

void		scan_format(t_format **form, char *opt)
{
	int				i;

	init_format(form);
	i = 1;
	while (opt[i] && !istag(opt[i]) && isflag(opt[i]))
		i++;
	(*form)->flags = isflag(opt[1]) ? ft_prf_strsub(opt, 1, i - 1) : NULL;
	(*form)->width = ft_prf_atoi(opt + i);
	while (opt[i] && !istag(opt[i]) && opt[i] != '.')
		i++;
	(*form)->prec = opt[i] == '.' ? ft_prf_atoi(opt + i + 1) : 0;
	(*form)->prec = (opt[i] == '.' && (*form)->prec == 0) ? -1 : (*form)->prec;
	(*form)->type = get_type(opt);
	while (opt[i] && !istag(opt[i]))
		i++;
	if (istag(opt[i]))
		(*form)->tag = opt[i];
}

int			ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	int			ret;
	t_format	*form;

	ret = 0;
	form = NULL;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		ret += putnstr(format, i, getprct((char*)format, i));
		i = getprct((char*)format, i);
		if (format[i])
		{
			scan_format(&form, (char*)format + i);
			ret += launch(args, form);
		}
		i += format_len((char*)format + i);
	}
	free(form);
	va_end(args);
	return (ret);
}
