/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:08 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:51 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memalloc(size_t size)
{
	char *m;

	if (!(m = malloc(sizeof(size_t) * size)))
		return (NULL);
	while (size > 0)
		m[--size] = 0;
	return ((void *)m);
}
