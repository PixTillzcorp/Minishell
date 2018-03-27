/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:38:38 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/07 17:38:42 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_var_env(char *content)
{
	char		*ret;
	int			i;

	i = 0;
	while (content[i] && content[i] != '=')
		i++;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '=')
	{
		ret[i] = content[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char		*parsing_setenv(char **cmd)
{
	char		*ret;

	if (!cmd || !cmd[1] || cmd[2])
	{
		ft_putstr_fd("setenv: wrong number of arguments.\
		\nusage: setenv [Name]=[Value]\n", STDERR_FILENO);
		return (NULL);
	}
	else if (!ft_strchr(cmd[1], '=') || cmd[1][0] == '='\
	|| !(ft_strchr(cmd[1], '=') + 1))
	{
		ft_putstr_fd("setenv: you need to give a value or a valid name.\
		\nusage: setenv [Name]=[Value]\n", STDERR_FILENO);
		return (NULL);
	}
	return ((ret = get_var_env(cmd[1])));
}

static char		*parsing_unsetenv(char **cmd)
{
	char		*ret;

	if (!cmd || !cmd[1] || cmd[2])
	{
		ft_putstr_fd("unsetenv: wrong number of arguments.\
		\nusage: unsetenv [Name]\n", STDERR_FILENO);
		return (NULL);
	}
	else if (ft_strchr(cmd[1], '='))
	{
		ft_putstr_fd("unsetenv: you need to give valid name.\
		\nusage: unsetenv [Name]\n", STDERR_FILENO);
		return (NULL);
	}
	return ((ret = get_var_env(cmd[1])));
}

int				ft_setenv(t_list **adr_env, char **cmd)
{
	t_list		*cpy;
	char		*tmp;
	char		*cmp;

	if (!(cmp = parsing_setenv(cmd)))
		return (1);
	cpy = (*adr_env);
	while (cpy)
	{
		tmp = get_var_env(cpy->content);
		if (!ft_strcmp(tmp, cmp))
		{
			if (cpy->content)
				free(cpy->content);
			cpy->content = ft_strdup(cmd[1]);
			return (ft_ret_free(cmp, ft_ret_free(tmp, 1)));
		}
		if (tmp)
			ft_memdel((void **)&tmp);
		cpy = cpy->next;
	}
	ft_lst_push_back(adr_env, ft_lstnew(cmd[1], ft_strlen(cmd[1])));
	return (ft_ret_free(cmp, 1));
}

int				ft_unsetenv(t_list **adr_env, char **cmd)
{
	t_list		*save;
	t_list		*cpy;
	char		*tmp;
	char		*cmp;

	if (!(cmp = parsing_unsetenv(cmd)))
		return (1);
	cpy = (*adr_env);
	save = NULL;
	while (cpy)
	{
		if (!ft_strcmp((tmp = get_var_env(cpy->content)), cmp))
		{
			free(cpy->content);
			if (!save)
				(*adr_env) = (cpy->next ? cpy->next : NULL);
			else
				save->next = (cpy->next ? cpy->next : NULL);
			ft_memdel((void **)&cpy);
			return (ft_ret_free(cmp, ft_ret_free(tmp, 1)));
		}
		save = ft_retvoid_free(tmp, cpy);
		cpy = cpy->next;
	}
	return (ft_ret_free(cmp, 1));
}
