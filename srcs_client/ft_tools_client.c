/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:07:04 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_client/client.h"

void	ft_tools_replace(char *c)
{
	if (*c == '\n')
		*c = ' ';
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_tools_clear(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void**)&tab[i]);
	}
}

int		ft_str_is_nbr(char *str)
{
	while (*str)
	{
		if ((ft_isdigit(*str)) == 0)
			return (1);
		str++;
	}
	return (1);
}

int		ft_check_file(char *path)
{
	struct stat buf;
	int			fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	if (fstat(fd, &buf) == -1)
	{
		close(fd);
		return (-2);
	}
	if (S_ISREG(buf.st_mode))
	{
		G(size) = buf.st_size;
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
