/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:05:04 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/31 18:05:07 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*prev;
	t_node	*corrent;

	if (*head == NULL || (*head)->next == NULL)
		exit(EXIT_FAILURE);
	prev = NULL;
	corrent = *head;
	while (corrent->next)
	{
		prev = corrent;
		corrent = corrent->next;
	}
	prev->next = NULL;
	corrent->next = *head;
	*head = corrent;
}

void	rra(t_node **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_node **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
