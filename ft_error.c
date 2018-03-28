/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:00:10 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/28 17:00:13 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_error_type(char *path, char *cmd, char *type)
{
	ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(cmd, 2);
	if (!ft_strcmp(type, "NODIR"))
		ft_putstr_fd(": Not a directory: ", 2);
	else if (!ft_strcmp(type, "ISDIR"))
		ft_putstr_fd(": This is a directory: ", 2);
	else if (!ft_strcmp(type, "PERM"))
		ft_putstr_fd(": Permission denied: ", 2);
	else if (!ft_strcmp(type, "NOFORD"))
		ft_putstr_fd(": No such file or directory: ", 2);
	ft_putendl_fd(path, 2);
	return (0);
}

static void	ft_cd_error(char *type)
{
	if (!ft_strcmp(type, "HOME"))
		ft_putstr_fd("cd: HOME variable not set.\n", 2);
	if (!ft_strcmp(type, "-NULL"))
		ft_putstr_fd("cd: PWD or OLDPWD not set.\n", 2);
}

void		ft_error(char *cmd, char *type)
{
	if (!ft_strcmp(cmd, "cd"))
		ft_cd_error(type);
}
