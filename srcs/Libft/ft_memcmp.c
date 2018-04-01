/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:09 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:52 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s01;
	unsigned char	*s02;

	s02 = (unsigned char *)s2;
	s01 = (unsigned char *)s1;
	while (n > 0)
	{
		if (*s01 != *s02)
			return ((unsigned char)*s01 - (unsigned char)*s02);
		s01++;
		s02++;
		n--;
	}
	return (0);
}
