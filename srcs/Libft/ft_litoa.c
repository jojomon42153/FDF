/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_litoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 01:54:34 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:49 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char			*ft_litoa(long long int n)
{
	char					*ret;
	int						size;
	unsigned long long int	i;

	size = ft_lintlen(n);
	if (!(ret = (char *)malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (n < 0)
	{
		i = -n;
		ret[0] = '-';
	}
	else
		i = n;
	if (i == 0)
		ret[0] = '0';
	while (i)
	{
		ret[--size] = i % 10 + '0';
		i /= 10;
	}
	return (ret);
}
