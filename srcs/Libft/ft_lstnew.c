/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:08 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:51 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(*ret))))
		return (NULL);
	if (content != 0)
	{
		if (!(ret->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	ret->next = NULL;
	return (ret);
}
