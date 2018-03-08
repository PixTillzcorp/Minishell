/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_give.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:41:39 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:41:49 by heinfalt         ###   ########.fr       */
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
	ret[i] = '\0';
	return (ret);
}

static char		*ft_give(char *env_var, char *val)
{
	char		*ret;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!env_var || !val)
		return (NULL);
	while (env_var[i] && env_var[i] != '=')
		i++;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * ft_strlen(val) + i + 2)))
		return (NULL);
	i = 0;
	while (env_var[i] && env_var[i] != '=')
		ret[j++] = env_var[i++];
	ret[j++] = '=';
	i = 0;
	while (val[i])
		ret[j++] = val[i++];
	ret[j] = '\0';
	free(env_var);
	return (ret);
}

void			ft_env_give(t_list **adr_env, char *var, char *val)
{
	t_list		*cpy;
	char		*tmp;

	cpy = (*adr_env);
	if (!cpy || !var || !val)
		return ;
	while (cpy)
	{
		tmp = get_var_env(cpy->content);
		if (!ft_strcmp(tmp, var))
		{
			cpy->content = ft_give(cpy->content, val);
			if (tmp)
				ft_memdel((void **)&tmp);
			return ;
		}
		if (tmp)
			ft_memdel((void **)&tmp);
		cpy = cpy->next;
	}
}
