/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_serv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:07:55 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

static void	ft_cd_error(int i)
{
	if ((i = 1))
	{
		ft_putstr("ERROR _ cd:cd:13: no such file or directory: ");
		ft_putendl(g()->cmd[1]);
	}
	else if ((i = 2))
	{
		ft_putstr("ERROR _ cd:cd:13: not a directory: ");
		ft_putendl(g()->cmd[1]);
	}
	else if ((i = 3))
	{
		ft_putstr("ERROOR _ cd:cd:13: permission denied: ");
		ft_putendl(g()->cmd[1]);
	}
}

void		ft_open_path(void)
{
	struct stat buf;
	int			i;

	i = lstat(g()->cmd[1], &buf);
	if (access(g()->cmd[1], F_OK))
		ft_cd_error(1);
	else if (i == 0 && !S_ISDIR(buf.st_mode))
		ft_cd_error(2);
	else if (access(g()->cmd[1], X_OK))
		ft_cd_error(3);
	else
	{
		if (chdir(G(cmd)[1]) == -1)
			printf("%s\n", "ERROR chdir = -1");
		else
			printf("\nSUCCESS\n");
	}
}

void		ft_cd(void)
{
	struct stat buf;
	char		*tmp;
	char		*tmp2;
	int			i;

	tmp2 = NULL;
	tmp2 = getcwd(tmp2, 1024);
	tmp = ft_strjoin(tmp2, "/");
	ft_memdel((void**)&tmp2);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, g()->cmd[1]);
	ft_memdel((void**)&tmp2);
	i = lstat(tmp, &buf);
	if (access(tmp, F_OK))
		ft_cd_error(1);
	else if (i == 0 && !S_ISDIR(buf.st_mode))
		ft_cd_error(2);
	else if (access(tmp, X_OK))
		ft_cd_error(3);
	else if (chdir(tmp) == -1)
		printf("%s\n", "ERROR chdir = -1");
	else
		printf("\nSUCCESS\n");
}

void		ft_mini_cd(void)
{
	if (g()->cmd[1])
	{
		if (g()->cmd[1][0] == '/')
			ft_open_path();
		else
			ft_cd();
	}
	else
	{
		if (chdir("/") == -1)
			printf("%s\n", "ERROR chidir = -1");
		else
			printf("\nSUCCESS\n");
	}
}
