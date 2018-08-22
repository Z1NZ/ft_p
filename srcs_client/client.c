/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 15:34:51 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:06:45 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_client/client.h"

t_env	*g(void)
{
	static t_env *sg;

	if (!sg)
		sg = (t_env *)malloc(sizeof(t_env));
	return (sg);
}

void	ft_signal(void)
{
	int i;

	i = 0;
	while (i < 32)
	{
		if (i != SIGCONT && i != SIGTSTP)
		{
			signal(i, ft_return);
		}
		i++;
	}
}

void	ft_init_cl(void)
{
	G(port) = 0;
	G(sock) = 0;
	G(adress) = NULL;
	ft_bzero(G(buff), 1024);
}

void	ft_start_client(void)
{
	G(sock) = create_client(G(adress), G(port));
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (ft_str_is_nbr(argv[2]) == 1)
		{
			ft_init_cl();
			if (!ft_strcmp(argv[1], "localhost"))
				G(adress) = "127.0.0.1";
			else
				G(adress) = argv[1];
			G(port) = ft_atoi(argv[2]);
			ft_start_client();
			ft_signal();
			if ((G(pid) = fork()) == 0)
				ft_louper_recpt();
			else
				ft_louper_send();
		}
		else
			printf("%s\n", "error <port>");
	}
	else
		printf("%s\n", "error argument exemple = ./client <ip> <port>");
	return (0);
}
