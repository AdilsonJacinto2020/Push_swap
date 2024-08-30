/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:02:17 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/31 18:02:19 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	swap(t_node **head)
{
	t_node	*aux;

	if (*head == NULL || (*head)->next == NULL)
		exit(EXIT_FAILURE);
	aux = NULL;
	aux = (*head)->next;
	(*head)->next = aux->next;
	aux->next = *head;
	*head = aux;
}

void	sa(t_node **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_node **head)
{
	swap(head);
	write(1, "sb\n", 3);
}
