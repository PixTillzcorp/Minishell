/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:38:52 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/07 17:38:56 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_path(char *path, char *cmd)
{
	t_stat		stats;

	if (!path)
		return (0);
	if (access(path, F_OK) == 0)
	{
		if (stat(path, &stats) < 0)
			exit(EXIT_FAILURE);
		if (ft_data_type(stats.st_mode & S_IFMT) == 'd')
		{
			if (access(path, X_OK) != 0)
				return (ft_error_type(path, cmd, "PERM"));
			return (1);
		}
		else
			return (ft_error_type(path, cmd, "NOTDIR"));
	}
	return (ft_error_type(path, cmd, "NOFORD"));
}

static void		ft_swap_dir(t_list **adr_env, char *tmp, char *old)
{
	if (!tmp || !old)
	{
		ft_error("cd", "-NULL");
		return ;
	}
	if (ft_check_path(old, "cd") && ft_check_path(tmp, "cd"))
	{
		if (chdir(old) < 0)
				exit(EXIT_FAILURE);
		ft_env_give(adr_env, "PWD", old);
		ft_env_give(adr_env, "OLDPWD", tmp);
	}
}

static void		ft_go_home(t_list **adr_env, char *tmp)
{
	char		*home;

	if (!(home = ft_env_val(adr_env, "HOME")))
	{
		ft_error("cd", "HOME");
		return ;
	}
	if (ft_check_path(home, "cd"))
	{
		if (chdir(home) < 0)
			exit(EXIT_FAILURE);
		ft_env_give(adr_env, "PWD", home);
		ft_env_give(adr_env, "OLDPWD", tmp);
	}
	free(home);
}

void			ft_change_dir(t_list **adr_env, char **cmd)
{
	char		*tmp;
	char		*old;

	if (!cmd || !cmd[0] || cmd[1])
	{
		ft_putstr_fd("cd: Wrong number of arguments\n", 2);
		return ;
	}
	old = ft_env_val(adr_env, "OLDPWD");
	tmp = ft_give_pwd();
	if (!ft_strcmp(cmd[0], "-"))
		ft_swap_dir(adr_env, tmp, old);
	else if (!ft_strcmp(cmd[0], "~"))
		ft_go_home(adr_env, tmp);
	else if (ft_check_path(cmd[0], "cd"))
	{
		if (chdir(cmd[0]) < 0)
			exit(EXIT_FAILURE);
		ft_env_give(adr_env, "OLDPWD", tmp);
		free(tmp);
		ft_env_give(adr_env, "PWD", (tmp = ft_give_pwd()));
	}
	free(old);
	free(tmp);
}
