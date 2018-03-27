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

t_list			*ft_envclone(char **environ)
{
	t_list		*env;
	int			i;

	i = 0;
	if (!environ)
		return (NULL);
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
	return (env);
}
