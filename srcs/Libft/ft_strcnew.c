/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:17 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:57 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char		*ft_strcnew(size_t size, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
		str[i++] = c;
	str[i] = 0;
	return (str);
}
