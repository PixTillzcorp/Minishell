/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:42:14 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:42:34 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		empty_gen(t_list **adr_env)
{
	char		*tmp;

	tmp = ft_give_pwd();
	tmp = ft_strjoin_free("PWD=", tmp, 'r');
	*adr_env = ft_lstnew(tmp, ft_strlen(tmp));
	free(tmp);
	ft_lst_push_back(adr_env, ft_lstnew("SHLVL=1", 7));
	ft_lst_push_back(adr_env, ft_lstnew("_=/usr/bin/env", 14));
}

t_list			*ft_envclone(char **environ)
{
	t_list		*env;
	int			i;

	i = 0;
	if (!environ)
		return (NULL);
	else if (environ[0] == NULL)
		empty_gen(&env);
	else
	{
		while (environ[i])
		{
			if (!i)
				env = ft_lstnew(environ[i], ft_strlen(environ[i]));
			else
			{
				ft_lst_push_back(&env, ft_lstnew(environ[i],\
				ft_strlen(environ[i])));
			}
			i++;
		}
	}
	return (env);
}
