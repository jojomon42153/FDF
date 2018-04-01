/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrdup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 03:54:00 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 04:01:46 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	wchar_t		*wstr2;
	int			i;

	i = -1;
	if (!(wstr2 = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(wstr) + 1)))
		return (NULL);
	while (wstr[++i])
		wstr2[i] = wstr[i];
	wstr2[i] = 0;
	return (wstr2);
}
