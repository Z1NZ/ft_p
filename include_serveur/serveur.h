/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 12:06:59 by srabah            #+#    #+#             */
/*   Updated: 2015/06/03 23:15:47 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVEUR_H

# define FT_SERVEUR_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <dirent.h>

typedef struct			s_env
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int					pid;
	char				buff[2048];
	int					ret;
	char				**cmd;
	off_t				size;
}						t_env;

# define G(x)			g()->x

t_env					*g(void);
int						sh_line_splite(char *line);
void					ft_open_path(void);
void					ft_cd(void);
void					ft_mini_cd();
int						create_server(int port);
void					ft_init_sv(void);
void					ft_start_sv(void);
void					ft_tools_clear(char ***tab);
void					ft_tools_replace(char *c);
void					ft_send_state_to_client(int sock_err);
int						ft_str_is_nbr(char *str);
int						ft_check_is_folder(char *path);
int						ft_check_write_in_dir(char *path);
int						ft_tools_check_in_dir(char *path, char *file);
int						ft_tab_char_len(char **tab);
void					looper(void);
void					ft_mini_ls(void);
void					ft_mini_pwd(void);
void					ft_mini_mkdir(void);
void					ft_mini_rmdir(void);
void					ft_exit_sv(void);
int						ft_check_file(char *path);
void					ft_recept_file(void);
void					ft_send_file(void);
void					ft_start_send(void);

#endif
