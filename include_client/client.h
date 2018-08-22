/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 13:37:07 by srabah            #+#    #+#             */
/*   Updated: 2015/06/08 21:06:32 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H

# define CLIENT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <netdb.h>
# include <sys/wait.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/socket.h>

typedef struct			s_env
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	char				*adress;
	char				buff[2048];
	int					ret;
	pid_t				pid;
	off_t				size;
	char				**cmd;
}						t_env;

# define G(x)		g()->x

t_env					*g(void);
int						tab_len(char **tab);
int						ft_str_is_nbr(char *str);
void					ft_tools_clear();
void					ft_init_cl(void);
int						create_client(char *adress, int port);
void					ft_start_client(void);
void					ft_send_file(char *ptr);
void					ft_louper_recpt(void);
void					ft_tools_replace(char *c);
int						ft_check_file(char *path);
void					ft_put_file(void);
void					ft_louper_send(void);
void					ft_recp_file();
void					ft_get_file();
void					ft_return(int t);

#endif
