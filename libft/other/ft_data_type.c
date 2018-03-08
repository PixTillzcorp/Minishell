/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:54:01 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 17:13:28 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	ft_data_type(mode_t type)
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
