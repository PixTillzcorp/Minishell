/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:38:58 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/07 17:39:00 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_clear(void)
{
	char		*output;

	if (!(output = tgetstr("cl", NULL)))
		return ;
	tputs(output, 0, ft_ret_putchar);
}
