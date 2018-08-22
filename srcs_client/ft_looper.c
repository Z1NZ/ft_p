/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_looper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiane <sofiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/07/20 07:57:39 by sofiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_client/client.h"

void	ft_louper_recpt(void)
{
	ft_bzero(G(buff), 2048);
	while ((recv(G(sock), G(buff), 2047, 0)) != -1)
	{
		if (ft_strcmp(G(buff), "exit") == 0)
			exit(1);
		else if (ft_strncmp(G(buff), "start", 5) == 0)
			ft_send_file(G(buff));
		else if (ft_strncmp(G(buff), "get", 3) == 0)
			ft_recp_file();
		else if (*G(buff) != '\0')
			printf("%s", G(buff));
		ft_bzero(G(buff), 2048);
		ft_tools_clear(&G(cmd));
	}
}

void	ft_louper_send(void)
{
	printf("%s", "< SHELL SERVER CONNECT >\n");
	while ((read(0, G(buff), 1023)) != -1)
	{
		if (!ft_strcmp(G(buff), "quit\n"))
		{
			ft_putstr_fd(G(buff), G(sock));
			wait4(G(pid), 0, 0, NULL);
			shutdown(G(cs), 2);
			close(G(cs));
			exit(1);
		}
		else if (!ft_strncmp(G(buff), "put", 3))
			ft_put_file();
		else if (!ft_strncmp(G(buff), "get", 3))
			ft_get_file();
		if (*G(buff) != '\0')
		{
			ft_putstr_fd(G(buff), G(sock));
			ft_bzero(G(buff), 2048);
		}
	}
}

void	ft_return(int t)
{
	(void)t;
	ft_putstr_fd("quit\n", G(sock));
	wait4(G(pid), 0, 0, NULL);
	shutdown(G(cs), 2);
	close(G(cs));
	exit(1);
}
