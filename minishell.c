#include "minishell.h"

static void		ft_free_tab(char **tabl)
{
	int		i;

	i = 0;
	if (tabl[i])
	{
		while (tabl[i])
			ft_memdel((void **)&tabl[i++]);
		ft_memdel((void **)&tabl[i]);
		free(tabl);
		tabl = NULL;
	}
}

static void	ft_bzero_free(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
	if (s)
		free(s);
}

int					main(int argc, char **argv, char **environ)
{
	t_list			*env;
	char			*path;
	char			**paths;
	int				done;

	argv = NULL;
	done = 1;
	if (argc != 1)
		return (0);
	env = ft_envclone(environ);
	ft_putfile("minishell-heinfalt.txt");
	while (done)
	{
		path = ft_env_val(&env, "PATH");
		paths = ft_strsplit(path, ':');
		done = extract_command(get_command_line(), &env, paths);
		if (paths)
			ft_free_tab(paths);
		free(path);
	}
	if (env)
		ft_lstdel(&env, ft_bzero_free);
	while (1)
		done = 1;
	return (0);
}