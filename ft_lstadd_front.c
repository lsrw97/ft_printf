#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	lst = &new;
}
int main (void)
{
	t_list *new;
	t_list **lst;
	t_list *list;

	// int *ptr;
	// int **pptr;
	// int ***ppptr;

	// ppptr = &pptr;
	// pptr = &ptr;

	new = malloc(sizeof(t_list));
	list = malloc(sizeof(t_list));

	char str[11] = "hello world";
	list->content = str;
	list->next = NULL;

	lst = &list;
	new->next = NULL;
	new->content = str;

		printf("%lu", sizeof(new));
		printf("new->next: %p, list->next: %p\n, lst: %p, list: %p\n\n", new->next, list->next, *lst, list);
	ft_lstadd_front(lst, new);
		printf("new->next: %p, list->next: %p\n, lst: %p, list: %p", new->next, list->next, lst, list);
}
