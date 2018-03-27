/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:39:08 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/07 17:39:14 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_free_tab(char **tabl)
{
	int			i;

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

static void		ft_bzero_free(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
	if (s)
		free(s);
}

int				main(int argc, char **argv, char **environ)
{
	t_list		*env;
	char		*path;
	char		**paths;
	int			done;

	argv = NULL;
	done = 1;
	if (argc != 1)
		return (1);
	env = ft_envclone(environ);
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
	return (0);
}
