/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:24:11 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 17:24:13 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_newpath(char *p, char *d)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(p) +\
	ft_strlen(d) + 2))))
		return (NULL);
	while (p[i])
		ret[j++] = p[i++];
	ret[j++] = '/';
	i = 0;
	while (d[i])
		ret[j++] = d[i++];
	ret[j] = '\0';
	return (ret);
}
