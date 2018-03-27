#include "../includes/libft.h"

int		ft_ret_freetab(char **tabl, int ret)
{
	if (tabl)
		ft_free_tab(tabl);
	return (ret);
}
