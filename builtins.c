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

void			ft_execve(char **cmd, char *path, char **envp)
{
	int			shell;
	int			i;

	i = 0;
	if ((shell = fork()) == 0)
	{
		if (execve(path, cmd, envp) == -1)
		{
			ft_printf("\033[31mminishell: Command not found:%s\n", cmd[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (shell > 0)
		wait(NULL);
	else
		ft_putstr_fd("fork error.\n", 2);
	if (envp)
		free(envp);
	if (path)
		free(path);
}
