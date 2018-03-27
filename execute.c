#include "minishell.h"

static int		ft_check_exec(char *path, char *cmd)
{
	t_stat		stats;

	if (!path)
		return (0);
	if (access(path, F_OK) == 0)
	{
		if (stat(path, &stats) < 0)
			exit(EXIT_FAILURE);
		if (ft_data_type(stats.st_mode & S_IFMT) == 'd')
			return (ft_error_type(path, cmd, "ISDIR"));
		if (access(path, X_OK) != 0)
			return (ft_error_type(path, cmd, "PERM"));
		else
			return (1);
	}
	return (ft_error_type(path, cmd, "NOFORD"));
}

static char		*ft_test_access(char **paths, char *cmd)
{
	char		*ret;
	int			i;

	i = 0;
	if (!cmd || !paths)
		return (NULL);
	while (paths[i])
	{
		paths[i] = ft_chrjoin_free(paths[i], '/', 1);
		paths[i] = ft_strjoin_free(paths[i], cmd, 'l');
		if (access(paths[i], F_OK) == 0)
		{
			ret = ft_strdup(paths[i]);
			return (ret);
		}
		else
			i++;
	}
	return (NULL);
}

static char		**ft_envtotab(t_list **adr_env)
{
	t_list		*cpy;
	char		**ret;
	int			i;

	i = 0;
	if (!(cpy = (*adr_env)))
		return (NULL);
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	if (!(cpy = (*adr_env)))
		return (NULL);
	while (cpy)
	{
		ret[i++] = (cpy->content);
		cpy = cpy->next;
	}
	return (ret);
}

int				extract_command(char **cmd, t_list **adr_env, char **paths)
{
	char		*path;

	if (!ft_strcmp(cmd[0], "env"))
		ft_env(adr_env);
	else if (!ft_strcmp(cmd[0], "setenv"))
		ft_setenv(adr_env, cmd);
	else if (!ft_strcmp(cmd[0], "unsetenv"))
		ft_unsetenv(adr_env, cmd);
	else if (!ft_strcmp(cmd[0], "cd"))
		ft_change_dir(adr_env, cmd + 1);
	else if (!ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd + 1);
	else if (!ft_strcmp(cmd[0], "exit"))
		return (ft_ret_freetab(cmd, 0));
	else if (adr_env)
	{
		if ((path = ft_test_access(paths, cmd[0])))
			ft_execve(cmd, path, ft_envtotab(adr_env));
		else
		{
			if (ft_check_exec(cmd[0], "minishell"))
				ft_execve(cmd, ft_strdup(cmd[0]), ft_envtotab(adr_env));
		}
	}
	return (ft_ret_freetab(cmd, 1));
}
