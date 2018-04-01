/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:12 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:55 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s != 0)
	{
		while (*s)
		{
			ft_putchar_fd(*s++, fd);
		}
	}
}