/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:40:09 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:40:12 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbrwords(char const *s, char c)
{
	int		none_c;
	size_t	ret;
	size_t	i;

	none_c = 0;
	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!none_c)
				ret++;
			none_c = 1;
		}
		else
			none_c = 0;
		i++;
	}
	return (ret);
}

static char	*ft_putintab(char const *s, char **tab, char c)
{
	size_t	word_begin;
	size_t	word_end;
	char	*word;

	word_begin = 0;
	word_end = 0;
	while (s[word_begin] == c)
		word_begin++;
	word_end = word_begin;
	while (s[word_end] && s[word_end] != c)
		word_end++;
	word = ft_strsub(s, word_begin, word_end - word_begin);
	*tab = word;
	return ((char *)(s + word_end));
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	n_word;
	char	**ret;
	char	*cpy;
	size_t	i;

	ret = NULL;
	i = 0;
	if (s)
	{
		cpy = (char *)s;
		n_word = ft_nbrwords(s, c);
		ret = (char **)ft_memalloc((n_word + 1) * sizeof(char *));
		if (!ret)
			return (NULL);
		while (i < n_word)
		{
			cpy = ft_putintab(cpy, ret + i, c);
			i++;
		}
		ret[n_word] = 0;
	}
	return (ret);
}
