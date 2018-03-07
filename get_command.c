#include "minishell.h"

static int	ft_check_white_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

static char	*ft_override(char *str, char *dest)
{
	int 	i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			dest[j++] = ' ';
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
		}
		else
			dest[j++] = str[i++];
	}
	dest[j] = '\0';
	return (dest);
}

static char	*ft_purif(char *str)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			len++;
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
		}
		else
		{
			len++;
			i++;
		}
	}
	ret = ft_override(str, (char *)ft_memalloc(sizeof(char) * len + 1));
	free(str);
	return (ret);
}

char		**get_command_line(void)
{
	char	**ret;
	char	*input;

	input = ft_strdup("");
	while (!ft_strcmp(input, "") || ft_check_white_str(input))
	{
		ft_putstr("\033[32m$\033[34m> \033[36m");
		free (input);
		if (get_next_line(STDIN_FILENO, &input) < 0)
			return (NULL);
	}
	input = ft_purif(input);
	ret = ft_strsplit(input, ' ');
	free(input);
	return (ret);
}
