#include "minishell.h"


static void	ft_cd_error(char *type)
{
	if (!ft_strcmp(type, "HOME"))
		ft_putstr_fd("cd: HOME variable not set.\n", 2);
	if (!ft_strcmp(type, "-NULL"))
		ft_putstr_fd("cd: PWD or OLDPWD not set.\n", 2);
}

void		ft_error(char *cmd, char *type)
{
	if (!ft_strcmp(cmd, "cd"))
		ft_cd_error(type);
}
