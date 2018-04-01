/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_chartostr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 08:33:58 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:47 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_chartostr(char c)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) * 2)))
		return (NULL);
	str[1] = '\0';
	str[0] = c;
	return (str);
}
