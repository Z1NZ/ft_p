/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_serv2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 16:31:02 by srabah            #+#    #+#             */
/*   Updated: 2015/06/23 16:31:03 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_serveur/serveur.h"

void		ft_tools_clear(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void**)&tab[i]);
	}
}

int			ft_tab_char_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		ft_tools_replace(char *c)
{
	if (*c == '\n')
		*c = ' ';
}

int			ft_str_is_nbr(char *str)
{
	while (*str)
	{
		if ((ft_isdigit(*str)) == 0)
			return (1);
		str++;
	}
	return (1);
}
