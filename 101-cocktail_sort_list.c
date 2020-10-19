#include "sort.h"
/**
 * swap_head - swaps a node at the beggining of the list
 * @list: Doubly linked list with nodes to sort acording to number n.
 * @aux: auxiliar node to compare
 */
void swap_head(listint_t **list, listint_t *aux)
{
	aux->prev->next = aux->next;
	if (aux->next)
		aux->next->prev = aux->prev;
	aux->next = aux->prev;
	aux->prev = aux->prev->prev;
	aux->next->prev = aux;
	*list = aux;
}
/**
 * swap_middle - swaps a node at the middle of the list
 * @aux: auxiliar node to compare
 */
void swap_middle(listint_t *aux)
{
	aux->prev->next = aux->next;
	aux->next->prev = aux->prev;
	aux->prev->prev->next = aux;
	aux->next = aux->prev;
	aux->prev = aux->next->prev;
	aux->next->prev = aux;
}
/**
 * swap_tail - swaps a node at the end of the list
 * @aux: auxiliar node to compare
 */
void swap_tail(listint_t *aux)
{
	aux->prev->next = aux->next;
	aux->next = aux->prev;
	aux->prev->prev->next = aux;
	aux->prev = aux->next->prev;
	aux->next->prev = aux;
}

void evaluate_swap(listint_t **list, listint_t *aux)
{
	if (!aux->prev->prev)
		swap_head(list, aux);
	else if (aux->prev->prev && aux->next)
		swap_middle(aux);
	else if (!aux->next)
		swap_tail(aux);
}

void cocktail_sort_list(listint_t **list)
{
	listint_t *aux = NULL, *tmp;
	int swap_flag = 1;

	if (!list || !(*list)->next)
		return;
	aux = tmp = (*list)->next;
	while (swap_flag)
	{
		aux = tmp, swap_flag = 0;
		while (aux)
		{
			if (aux->n < aux->prev->n)
			{
				evaluate_swap(list, aux);
				print_list(*list), swap_flag = 1;
			}
			if (aux->next != NULL)
				aux = aux->next;
			else
				break;
		}
		aux = aux->prev;
		while (aux->prev)
		{
			if (aux->prev->n > aux->n)
			{
				evaluate_swap(list, aux);
				print_list(*list), swap_flag = 1;
			}
			else if (aux->prev)
				aux = aux->prev;
		}
	}
}
