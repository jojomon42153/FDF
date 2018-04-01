/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalnum.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:05 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:31:48 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

int		ft_isalnum(int c)
{
	return ((ft_isalpha(c) == 1 || ft_isdigit(c) == 1) ? 1 : 0);
}
