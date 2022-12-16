#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	lastnode = lst;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}

// int main (void)
// {
// 	t_list *new;
// 	t_list **lst;
// 	t_list *list;
// 	t_list *new2;

// 	// int *ptr;
// 	// int **pptr;
// 	// int ***ppptr;

// 	// ppptr = &pptr;
// 	// pptr = &ptr;

// 	new = malloc(sizeof(t_list));
// 	new2 = malloc(sizeof(t_list));
// 	list = malloc(sizeof(t_list));

// 	char str[11] = "hello world";
// 	list->content = str;
// 	list->next = NULL;

// 	lst = &list;
// 	new->next = list;
// 	new->content = str;
// 	new2->next = new;
// 	new2->content = str;

// 	printf("%p\n", ft_lstlast(list));
// 	printf("new2: %p, new2->next: %p, new: %p, new->next: %p, list: %p, list->next: %p\n\n", new2, new2->next, new, new->next, list, list->next);
// }
