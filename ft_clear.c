#include "minishell.h"

void			ft_clear(void)
{
	char		*output;

	if (!(output = tgetstr("cl", NULL)))
		return ;
	tputs(output, 0, ft_ret_putchar);
}
