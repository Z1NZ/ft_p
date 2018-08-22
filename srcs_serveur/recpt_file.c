/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recpt_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:07:47 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

int			ft_check_file(char *path)
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

static void	ft_trans(int fd)
{
	char	*tmp;
	int		size;

	size = ft_atoi(G(cmd)[3]);
	ft_bzero(G(buff), 2048);
	tmp = ft_strjoin("start ", G(cmd)[1]);
	ft_putstr_fd(tmp, STDOUT_FILENO);
	while (size && size > 0)
	{
		G(ret) = read(G(cs), G(buff), 2047);
		size -= G(ret);
		write(fd, G(buff), G(ret));
		ft_bzero(G(buff), 2048);
	}
	ft_tools_clear(&G(cmd));
	close(fd);
}

void		ft_recept_file(void)
{
	int		fd;

	fd = 0;
	if (ft_tab_char_len(G(cmd)) == 4)
	{
		if (ft_check_file(G(cmd)[2]) == -1)
		{
			if ((fd = open(G(cmd)[2], O_CREAT | O_WRONLY)) > 0)
				ft_trans(fd);
			else
				ft_putstr_fd("error de O_CREAT\n", STDOUT_FILENO);
		}
		else
			ft_putstr_fd("error file already in the folder\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("error'\n", STDOUT_FILENO);
}
