#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	lastnode = ft_lstlast(*lst);
	lastnode->next = new;

}

int main (void)
{
	t_list *new;
	t_list **lst;
	t_list *list;
	t_list *new2;

	// int *ptr;
	// int **pptr;
	// int ***ppptr;

	// ppptr = &pptr;
	// pptr = &ptr;

	new = malloc(sizeof(t_list));
	new2 = malloc(sizeof(t_list));
	list = malloc(sizeof(t_list));

	char str[11] = "hello world";
	list->content = str;
	list->next = NULL;

	lst = &new;
	new->next = new2;
	new->content = str;
	new2->next = NULL;
	new2->content = str;
	printf("new: %p, new->next: %p, new2: %p, new2->next: %p, list: %p, list->next: %p\n\n", new, new->next, new2, new2->next, list, list->next);

	ft_lstadd_back(lst, list);
	printf("new: %p, new->next: %p, new2: %p, new2->next: %p, list: %p, list->next: %p\n\n", new, new->next, new2, new2->next, list, list->next);
}
