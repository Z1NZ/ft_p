/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_looper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiane <sofiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 15:24:45 by srabah            #+#    #+#             */
/*   Updated: 2015/07/20 07:50:39 by sofiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

static void	hub(void)
{
	if (!ft_strcmp(G(cmd)[0], "ls"))
		ft_mini_ls();
	else if (!ft_strcmp(G(cmd)[0], "cd"))
		ft_mini_cd();
	else if (!ft_strcmp(G(cmd)[0], "pwd"))
		ft_mini_pwd();
	else if (!ft_strcmp(G(cmd)[0], "quit"))
	{
		ft_exit_sv();
		exit(1);
	}
	else if (!ft_strcmp(G(cmd)[0], "mkdir"))
		ft_mini_mkdir();
	else if (!ft_strcmp(G(cmd)[0], "rmdir"))
		ft_mini_rmdir();
	else if (!ft_strcmp(G(cmd)[0], "put"))
		ft_recept_file();
	else if (!ft_strcmp(G(cmd)[0], "get"))
		ft_send_file();
	else if (!ft_strcmp(G(cmd)[0], "start"))
		ft_start_send();
}

void		looper(void)
{
	if ((dup2(G(cs), STDOUT_FILENO) != -1) &&
		(dup2(G(cs), STDERR_FILENO) != -1))
	{
		while ((G(ret) = read(G(cs), G(buff), 1023)))
		{
			ft_striter(G(buff), ft_tools_replace);
			G(cmd) = ft_strsplit(G(buff), ' ');
			if (G(cmd)[0])
				hub();
			ft_bzero(G(buff), 2048);
			ft_tools_clear(&G(cmd));
		}
	}
	else
		printf("%s\n", "error dup2");
}
