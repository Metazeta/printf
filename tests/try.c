/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   try.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 10:49:16 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 16:27:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		main(int ac, char **av)
{
	//char	*line;
	//int		ret;
	int		read;
	// wchar_t str[4];
    //
	(void)ac;
	(void)av;
//	ft_putendl("ENTER INPUT");
	// while((ret = get_next_line(1,&line)) == 1)
	// {
		//ret = get_next_line(1,&line);
		printf("+===FT_PRINTF===+\n");
		//read = ft_printf("111%s333", "222");
		//read = ft_printf("111333");
		//printf("\nRETURNS %d\n", read);
		read = ft_printf("%0d", -579);
		//read = ft_printf("%");
		//read = ft_printf("%x", ft_strsplit(line, ',')[0], ft_strsplit(line, ',')[1]);
		printf("\nRETURNS %d\n", read);
		printf("-=====PRINTF====-\n");
	//	printf(ft_strsplit(line, ',')[0]);
		read = printf("%0d", -579);
		//read = printf("%2s", ft_strsplit(line, ',')[0], ft_strsplit(line, ',')[1]);
		printf("\nRETURNS %d\n",  read);
		//ft_putendl("ENTER INPUT");
	// }
	// str[0] = u'@';
	// str[1] = u'Ḁ';
	// str[2] = u'@';
	// str[3] = 0;
	// ft_putwstr(str);
	return (0);
}
