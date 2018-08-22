/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:07:48 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

void		ft_send_state_to_client(int sock_err)
{
	if (sock_err == -1)
		send(G(cs), "ERROR", 6, 0);
}

int			ft_check_is_folder(char *path)
{
	struct stat *buf;
	int			fd;

	buf = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	if (fstat(fd, buf) == -1)
	{
		close(fd);
		return (-2);
	}
	if (S_ISDIR(buf->st_mode))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int			ft_check_write_in_dir(char *path)
{
	int fd;

	if ((fd = open(path, O_RDWR)) == -1)
		return (-1);
	close(fd);
	return (1);
}

int			ft_tools_check_in_dir(char *path, char *file)
{
	struct dirent	*dp;
	DIR				*dir;

	if ((dir = opendir(path)) == NULL)
	{
		return (-1);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dp->d_name, file) == 0)
		{
			closedir(dir);
			return (-2);
		}
	}
	closedir(dir);
	return (0);
}
