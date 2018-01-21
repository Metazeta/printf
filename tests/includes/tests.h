/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <eruaud@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 11:27:17 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 14:15:27 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include "libunit.h"
#include "libft.h"
#include "printf.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

# define NUM_TEST 3

int		prf_launcher(void);
int		prf_test_01(void);
int		prf_test_02(void);
int		prf_test_03(void);

#endif
