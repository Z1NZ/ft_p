/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 14:07:20 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:07:44 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"
#include <signal.h>

t_env	*g(void)
{
	static t_env *sg;

	if (!sg)
		sg = malloc(sizeof(t_env));
	return (sg);
}

int		main(int argc, char *argv[])
{
	signal(SIGCHLD, SIG_IGN);
	if (argc == 2)
	{
		if (ft_str_is_nbr(argv[1]) == 1)
		{
			ft_init_sv();
			G(port) = ft_atoi(argv[1]);
			ft_start_sv();
			while ((G(cs) = accept(G(sock),
				(struct sockaddr*)&G(csin), &G(cslen))))
			{
				if ((G(pid) = fork()) == 0)
					looper();
			}
			close(G(cs));
		}
		else
			printf("%s\n", "error <port>");
	}
	else
		printf("%s\n", "error argument exemple = ./serveur <port>");
	(G(sock) != 0) ? close(G(sock)) : ' ';
	return (0);
}
