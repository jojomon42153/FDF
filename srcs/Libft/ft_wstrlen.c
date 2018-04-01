/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 04:01:56 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 04:03:36 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}