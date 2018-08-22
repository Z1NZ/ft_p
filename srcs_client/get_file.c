/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiane <sofiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/07/20 07:55:29 by sofiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_client/client.h"

void		ft_get_file(void)
{
	char *tmp;

	tmp = ft_strdup(G(buff));
	ft_striter(tmp, ft_tools_replace);
	G(cmd) = ft_strsplit(tmp, ' ');
	if (tab_len(G(cmd)) == 3)
	{
		if (ft_check_file(G(cmd)[2]) == -1)
			ft_putstr_fd(G(buff), G(sock));
		else
			printf("eroor2.2 file already exist\n < SHELL SERVER CONNECT >\n");
	}
	else
		printf("error77 argument\n < SHELL SERVER CONNECT >\n");
	ft_memdel((void **)&tmp);
	ft_bzero(G(buff), 2048);
}

static void	ft_transfere(char *tmp, int size, int fd)
{
	size = ft_atoi(G(cmd)[3]);
	ft_bzero(G(buff), 2048);
	tmp = ft_strjoin("start ", G(cmd)[1]);
	ft_putstr_fd(tmp, G(sock));
	ft_putstr_fd("\n", G(sock));
	while (size)
	{
		G(ret) = read(G(sock), G(buff), 2047);
		size -= G(ret);
		write(fd, G(buff), G(ret));
		ft_bzero(G(buff), 2048);
	}
	ft_tools_clear(&G(cmd));
	close(fd);
}

void		ft_recp_file(void)
{
	char	*tmp;
	int		fd;
	int		size;

	size = 0;
	fd = 0;
	tmp = ft_strdup(G(buff));
	ft_striter(tmp, ft_tools_replace);
	G(cmd) = ft_strsplit(G(buff), ' ');
	if (tab_len(G(cmd)) == 4)
	{
		if (ft_check_file(G(cmd)[2]) == -1)
		{
			if ((fd = open(G(cmd)[2], O_CREAT | O_WRONLY)) > 0)
				ft_transfere(tmp, size, fd);
			else
				printf("%s\n", "error de O_CREAT < SHELL SERVER CONNECT >\n");
		}
		else
			printf("%s\n", "eroor already exist\n < SHELL SERVER CONNECT >");
	}
	else
		printf("%s\n", "error2 < SHELL SERVER CONNECT >\n");
}
