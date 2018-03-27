/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:41:53 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:42:12 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	return (ret);
}

char			*ft_env_val(t_list **adr_env, char *env_var)
{
	t_list		*cpy;
	char		*tmp;

	if (!adr_env || !(*adr_env))
		return (NULL);
	cpy = (*adr_env);
	while (cpy)
	{
		tmp = get_var_env(cpy->content);
		if (!ft_strcmp(tmp, env_var))
		{
			free(tmp);
			tmp = ft_strdup(ft_strchr(cpy->content, '=') + 1);
			return ((!ft_strcmp(tmp, "") ? NULL : tmp));
		}
		else
			cpy = cpy->next;
		free(tmp);
	}
	return (NULL);
}
