/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:21:38 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 21:27:02 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

int		ft_putwstr(wchar_t *str)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (str[i])
		ret += ft_putwchar(str[i++]);
	return (ret);
}
