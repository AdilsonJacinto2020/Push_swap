/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:14:27 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/30 18:14:28 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_greatest(t_node *head)
{
	t_node	*aux;
	int		greatest;

	aux = head;
	greatest = aux->data;
	while (aux)
	{
		if (aux->data > greatest)
			greatest = aux->data;
		aux = aux->next;
	}
	return (greatest);
}

int	ft_find_position(t_node *head, int value)
{
	int	position;

	position = 0;
	while (head)
	{
		if (head->data == value)
			return (position);
		position++;
		head = head->next;
	}
	return (-1);
}

int	ft_smallest(t_node *head)
{
	t_node	*aux;
	int		smallest;

	aux = head;
	smallest = aux->data;
	while (aux)
	{
		if (aux->data < smallest)
			smallest = aux->data;
		aux = aux->next;
	}
	return (smallest);
}

int	ft_smallest_index(t_node *head)
{
	t_node	*aux;
	int		smallest_index;

	aux = head;
	smallest_index = 0;
	while (aux)
	{
		if (aux->data == ft_smallest(aux))
			return (smallest_index);
		smallest_index++;
		aux = aux->next;
	}
	return (-1);
}
