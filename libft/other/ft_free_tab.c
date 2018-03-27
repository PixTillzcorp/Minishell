#include "../includes/libft.h"

void			ft_free_tab(char **tabl)
{
	int			i;

	i = 0;
	if (tabl[i])
	{
		while (tabl[i])
			ft_memdel((void **)&tabl[i++]);
		ft_memdel((void **)&tabl[i]);
		free(tabl);
		tabl = NULL;
	}
}
