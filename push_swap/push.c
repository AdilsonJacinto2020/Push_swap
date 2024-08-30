/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:07:14 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/31 18:07:16 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	push(t_node **head)
{
	t_node	*aux;
	int		pop;

	pop = 0;
	aux = *head;
	if (aux == NULL)
		exit(EXIT_FAILURE);
	*head = aux->next;
	pop = aux->data;
	free(aux);
	return (pop);
}

int	pa(t_node **head)
{
	write(1, "pa\n", 3);
	return (push(head));
}

int	pb(t_node **head)
{
	write(1, "pb\n", 3);
	return (push(head));
}
