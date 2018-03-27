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

static char		*ft_give_pwd(void)
{
	char		*buff;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * 200)))
		return (NULL);
	getcwd(buff, 200);
	return (buff);
}

static int		ft_check_path(char *path, char *cmd)
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
			{
				ft_printf("\033[31m%s: Permission denied: %s\n", cmd, path);
				return (0);
			}
			return (1);
		}
		else
		{
			ft_printf("\033[31m%s: Not a directory: %s\n", cmd, path);
			return (0);
		}
	}
	ft_printf("\033[31m%s: No such file or directory: %s\n", cmd, path);
	return (0);
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
	char		*new;
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
		ft_env_give(adr_env, "PWD", (new = ft_newpath(tmp, cmd[0])));
		ft_env_give(adr_env, "OLDPWD", tmp);
		free(new);
	}
	free(old);
	free(tmp);
}
