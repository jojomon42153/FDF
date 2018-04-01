/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_strlst.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:10 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:53 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	ft_print_strlst(t_list **alst)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = *alst;
	while (ptr != NULL)
	{
		if (i == 0)
			ft_putstr("Begin list\n");
		ft_putstr("\nmaillon ");
		ft_putnbr(i);
		ft_putstr("\ncontent : ");
		ft_putstr(ptr->content);
		ft_putstr("\nsize : ");
		ft_putnbr(ptr->content_size);
		ft_putchar('\n');
		i++;
		ptr = ptr->next;
	}
	ft_putstr("\nEnd list");
}
