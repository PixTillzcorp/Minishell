#include "minishell.h"

static int		echo_option(char c)
{
	ft_putstr_fd("echo: illegal option:", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (-1);
}

void			ft_echo(char **cmd)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	if (cmd[i])
	{
		if (cmd[i][0] == '-')
		{
			if (cmd[i][1] == 'n')
				n = 1;
			else
				n = echo_option(cmd[i][1]);
			i++;
		}
		while (cmd[i] && n >= 0)
		{
			ft_putstr(cmd[i++]);
			if (cmd[i])
				ft_putchar(' ');
		}
	}
	if (n == 0)
		ft_putchar('\n');
}
