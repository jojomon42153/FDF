/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchartowstr.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 03:35:51 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 03:50:16 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

wchar_t		*ft_wchartowstr(wchar_t c)
{
	wchar_t	*wstr;

	if (!(wstr = (wchar_t *)malloc(sizeof(wchar_t) * 2)))
		return (NULL);
	wstr[1] = 0;
	wstr[0] = c;
	return (wstr);
}
