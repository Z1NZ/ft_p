/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 17:43:33 by srabah            #+#    #+#             */
/*   Updated: 2015/06/13 17:43:42 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

void	ft_mini_ls(void)
{
	pid_t	tpid;
	int		status;

	G(cmd)[0] = "/bin/ls";
	if ((tpid = fork()) == 0)
		execv("/bin/ls", G(cmd));
	else
		wait4(tpid, &status, WUNTRACED, NULL);
}

void	ft_mini_mkdir(void)
{
	pid_t	tpid;
	int		status;

	G(cmd)[0] = "/bin/mkdir";
	if ((tpid = fork()) == 0)
		execv("/bin/mkdir", G(cmd));
	else
		wait4(tpid, &status, WUNTRACED, NULL);
}

void	ft_mini_rmdir(void)
{
	pid_t	tpid;
	int		status;

	G(cmd)[0] = "/bin/rmdir";
	if ((tpid = fork()) == 0)
		execv("/bin/rmdir", G(cmd));
	else
		wait4(tpid, &status, WUNTRACED, NULL);
}

void	ft_mini_pwd(void)
{
	pid_t	tpid;
	int		status;

	G(cmd)[0] = "/bin/pwd";
	if ((tpid = fork()) == 0)
		execv("/bin/pwd", G(cmd));
	else
		wait4(tpid, &status, WUNTRACED, NULL);
}

void	ft_exit_sv(void)
{
	ft_putstr_fd("exit", G(cs));
	shutdown(G(cs), 2);
	close(G(cs));
}
