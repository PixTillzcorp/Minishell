#include "../includes/libft.h"

void			ft_env(t_list **adr_env)
{
	t_list		*cpy;

	if (adr_env)
	{
		cpy = (*adr_env);
		while (cpy)
		{
			ft_putendl(cpy->content);
			cpy = cpy->next;
		}
	}
}
