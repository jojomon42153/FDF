/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulitoa.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 03:18:23 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:32:03 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char			*ft_ulitoa(unsigned long long int n)
{
	char					*ret;
	int						size;

	size = ft_ulintlen(n);
	if (!(ret = (char *)malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		ret[--size] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}
