#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (temp->next == NULL)
		i++;
	return (i);
}

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

	lst = &list;
	new->next = list;
	new->content = str;
	new2->next = new;
	new2->content = str;

	printf("%d\n", ft_lstsize(new2));
	printf("new2: %p, new2->next: %p, new: %p, new->next: %p, list: %p, list->next: %p\n\n", new2, new2->next, new, new->next, list, list->next);
}
