/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiane <sofiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/07/20 07:55:47 by sofiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_client/client.h"

void	ft_put_file(void)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strdup(G(buff));
	ft_striter(tmp, ft_tools_replace);
	G(cmd) = ft_strsplit(tmp, ' ');
	if (tab_len(G(cmd)) == 3)
	{
		if (ft_check_file(G(cmd)[1]) == 1)
		{
			tmp = ft_strjoin(tmp, ft_itoa(G(size)));
			tmp2 = ft_strjoin(tmp, "\n");
			printf("%s\n", tmp2);
			ft_putstr_fd(tmp2, G(sock));
		}
		else
			printf("ghost in the shell\n  < SHELL SERVER CONNECT >\n");
	}
	else
		printf("error argument\n < SHELL SERVER CONNECT >\n");
	ft_memdel((void **)&tmp);
	ft_bzero(G(buff), 2048);
}

void	ft_send_file(char *ptr)
{
	char	buffer[2048];
	int		fd;

	fd = 0;
	G(cmd) = ft_strsplit(ptr, ' ');
	if (tab_len(G(cmd)) == 2)
	{
		fd = open(G(cmd)[1], O_RDONLY);
		ft_bzero(buffer, 2048);
		if (fd == -1)
			printf("error file descriptor\n < SHELL SERVER CONNECT >\n");
		else
		{
			ft_bzero(buffer, 2048);
			while (read(fd, buffer, 2047))
			{
				ft_putstr_fd(buffer, G(sock));
				ft_bzero(buffer, 2048);
			}
			close(fd);
		}
	}
	else
		printf("%s\n", ptr);
}
