/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 15:30:10 by jmonneri     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 15:53:35 by jmonneri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../incs/fdf.h"

t_list	*ft_srchncreate(size_t fd)
{
	t_list			*tmp;
	static t_list	*lst = NULL;

	tmp = lst;
	if (!lst)
	{
		if (!(lst = ft_lstnew("", 1)))
			return (NULL);
		lst->content_size = fd;
		return (lst);
	}
	else
		while (tmp)
		{
			if (tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
	if (!(tmp = ft_lstnew("", 1)))
		return (NULL);
	tmp->content_size = fd;
	ft_lstadd(&lst, tmp);
	return (tmp);
}

int		ft_getthisfukingline(t_list *lst, int i, char *str, char **line)
{
	int				j;
	char			*tmp;

	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if ((tmp = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		return (-1);
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	*line = tmp;
	if (ft_strcmp(tmp, str) != 0)
	{
		if (!(str = ft_strdup(str + i + 1)))
			return (-1);
	}
	else
		str = "";
	free(lst->content);
	lst->content = str;
	return (1);
}

int		ft_read(t_list *lst, int i, char *str, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;

	while (1)
	{
		if (i == 0 && !ft_strchr(str, '\n'))
		{
			if ((ret = read((int)lst->content_size, buf, BUFF_SIZE)) == -1)
				return (-1);
			if (ret == 0)
				i = 1;
			else
			{
				buf[ret] = '\0';
				if (!(lst->content = ft_strjoin(lst->content, buf)))
					return (-1);
				ft_strdel(&str);
				str = lst->content;
			}
		}
		else if (ft_strcmp(str, "") == 0)
			return (0);
		else
			return (ft_getthisfukingline(lst, 0, (char *)lst->content, line));
	}
}

int		get_next_line(int fd, char **line)
{
	t_list			*lst;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(lst = ft_srchncreate((size_t)fd)))
		return (-1);
	*line = NULL;
	fd = ft_read(lst, 0, (char *)lst->content, line);
	return (fd);
}
