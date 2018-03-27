#include "../includes/libft.h"

char			*ft_give_pwd(void)
{
	char		*buff;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * 200)))
		return (NULL);
	getcwd(buff, 200);
	return (buff);
}
