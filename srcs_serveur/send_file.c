/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:38:47 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:07:46 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

void		ft_send_file(void)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strdup(G(buff));
	ft_striter(tmp, ft_tools_replace);
	G(cmd) = ft_strsplit(tmp, ' ');
	if (ft_tab_char_len(G(cmd)) == 3)
	{
		if (ft_check_file(G(cmd)[1]) == 1)
		{
			tmp = ft_strjoin(tmp, ft_itoa(G(size)));
			tmp2 = ft_strjoin(tmp, "\n");
			ft_putstr_fd(tmp2, STDOUT_FILENO);
		}
		else
			ft_putstr_fd("ghost in the eroor\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd("error argument\n", STDOUT_FILENO);
	ft_memdel((void **)&tmp);
	ft_bzero(G(buff), 2048);
}

void		ft_start_send(void)
{
	char	buffer[2048];
	int		fd;

	fd = 0;
	if (ft_tab_char_len(G(cmd)) == 2)
	{
		ft_bzero(buffer, 2048);
		fd = open(G(cmd)[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("error file descriptor serveur\n", STDOUT_FILENO);
		}
		else
		{
			ft_bzero(buffer, 2048);
			while (read(fd, buffer, 2047))
			{
				ft_putstr_fd(buffer, STDOUT_FILENO);
				ft_bzero(buffer, 2048);
			}
			close(fd);
		}
	}
	else
		ft_putstr_fd("to many argument for ft_start_send", STDOUT_FILENO);
}
