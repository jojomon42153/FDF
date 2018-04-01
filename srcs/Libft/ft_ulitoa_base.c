/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulitoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 03:24:02 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 16:44:59 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_convert_base(int n)
{
	if (n >= 10)
		return (n - 10 + 'A');
	else
		return (n + '0');
}

static int	ft_ulintlen_base(unsigned long long int n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		*ft_ulitoa_base(unsigned long long int n, int base)
{
	char					*ret;
	int						size;

	size = ft_ulintlen_base(n, base);
	if (!(ret = (char *)malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		ret[--size] = ft_convert_base(n % base);
		n /= base;
	}
	return (ret);
}
