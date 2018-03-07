#include "../includes/libft.h"

t_list			*ft_envclone(char **environ)
{
	t_list		*env;
	int			i;

	i = 0;
	while (environ[i])
	{
		if (!i)
			env = ft_lstnew(environ[i], ft_strlen(environ[i]));
		else
			ft_lst_push_back(&env, ft_lstnew(environ[i], ft_strlen(environ[i])));
		i++;
	}
	return (env);
}
