/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:40:50 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:40:58 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putfile(char *path)
{
	char	*line;
	int		fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
}
