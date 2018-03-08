/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:32:29 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:32:32 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/includes/libft.h"
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <term.h>

typedef struct stat		t_stat;

typedef struct winsize	t_ws;

char					**get_command_line(void);
int						extract_command(char **cmd, t_list **adr_env,\
						char **path);
int						ft_is_builtin(char *str);

void					ft_change_dir(t_list **adr_env, char **cmd);
void					ft_printf_working_dir(void);
void					ft_execve(char **cmd, char *path);
void					ft_clear(void);
void					ft_echo(char **cmd);

t_list					*ft_clone_env(void);
void					ft_env(t_list **adr_env);
int						ft_setenv(t_list **adr_env, char **cmd);
int						ft_unsetenv(t_list **adr_env, char **cmd);

#endif
