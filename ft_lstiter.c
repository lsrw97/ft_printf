#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	if (!f || !node)
		return ;
	while (!node->next)
	{
		f(node->content);
		node = node->next;
	}
}
