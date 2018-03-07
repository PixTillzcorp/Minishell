#include "minishell.h"

static char		*ft_newpath(char *p, char *d)
{
	char		*ret;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(p) +\
	ft_strlen(d) + 2))))
		return (NULL);
	while (p[i])
		ret[j++] = p[i++];
	ret[j++] = '/';
	i = 0;
	while (d[i])
		ret[j++] = d[i++];
	ret[j] = '\0';
	return (ret);
}

static char		*ft_give_pwd(void)
{
	char		*buff;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * 200)))
		return (NULL);
	getcwd(buff, 200);
	return (buff);
}

static char		ft_data_type(mode_t type)
{
	if (type == S_IFDIR)
		return ('d');
	else if (type == S_IFCHR)
		return ('c');
	else if (type == S_IFLNK)
		return ('l');
	else if (type == S_IFBLK)
		return ('b');
	else if (type == S_IFSOCK)
		return ('s');
	else if (type == S_IFIFO)
		return ('p');
	else if (type == S_IFREG)
		return ('-');
	return (0);
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

void			ft_change_dir(t_list **adr_env, char **cmd)
{
	char		*new;
	char		*tmp;
	char		*old;

	if (!cmd || !cmd[0])
		return ;
	old = ft_env_val(adr_env, "OLDPWD");
	tmp = ft_give_pwd();
	ft_printf("old = %s | tmp = %s\n", old, tmp);
	if (!ft_strcmp(cmd[0], "-"))
	{
		if (chdir(old) < 0)
			exit(EXIT_FAILURE);
		ft_env_give(adr_env, "PWD", old);
		ft_env_give(adr_env, "OLDPWD", tmp);
	}
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
