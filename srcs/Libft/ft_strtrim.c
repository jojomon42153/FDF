/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:18 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:32:02 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	size;

	if (s == 0)
		return (NULL);
	size = ft_strlen(s) - 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
		size--;
	return (ft_strsub(s, i, size - i + 1));
}
