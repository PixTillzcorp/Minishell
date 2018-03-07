/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:38:21 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/07 17:38:31 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_printf_working_dir(void)
{
	char		*buff;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * 200)))
		return ;
	getcwd(buff, 200);
	ft_putstr(buff);
	ft_putchar('\n');
	free(buff);
}

void			ft_execve(char **cmd, char *path)
{
	int			shell;

	if ((shell = fork()) == 0)
		execve(path, cmd, NULL);
	else
		wait(NULL);
}
