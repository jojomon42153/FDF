/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_litoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 02:35:34 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 16:44:52 by jmonneri    ###    #+. /#+    ###.fr     */
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

static int	ft_lintlen_base(long long int n, int base)
{
	int i;

	i = 0;
	if (base == 10 && n < 0)
		i++;
	if (n == 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		*ft_litoa_base(long long int n, int base)
{
	char					*ret;
	int						size;
	unsigned long long int	i;

	size = ft_lintlen_base(n, base);
	if (!(ret = (char *)malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	ret[size] = '\0';
	if (n < 0)
	{
		i = -n;
		if (base == 10)
			ret[0] = '-';
	}
	else
		i = n;
	if (i == 0)
		ret[0] = '0';
	while (i)
	{
		ret[--size] = ft_convert_base(i % base);
		i /= base;
	}
	return (ret);
}
