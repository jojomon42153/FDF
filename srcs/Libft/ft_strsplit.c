/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 19:14:17 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 17:47:58 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/libft.h"

static	size_t			nbmots(char const *s, char c)
{
	int		i;
	int		count;
	size_t	mots;

	mots = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count = 0;
		else if (s[i] != c && count == 0)
		{
			mots++;
			count = 1;
		}
		i++;
	}
	return (mots);
}

static	size_t			lgmot(char const *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

char					**ft_strsplit(char *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (!s || !(tab = malloc(sizeof(*tab) * (nbmots(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			if (!(tab[j] = malloc(sizeof(**tab) * (lgmot(s, i, c) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
