/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:23:17 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/26 10:23:19 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_is_sorted(t_node *head)
{
	t_node	*aux;

	aux = head;
	while (aux->next)
	{
		if (aux->data > aux->next->data)
			return (-1);
		aux = aux->next;
	}
	return (0);
}

int	ft_count_node(t_node *head)
{
	int		count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

int	find_equal_values(t_node *head)
{
	t_node	*inner;
	t_node	*outer;

	outer = head;
	while (outer != NULL)
	{
		inner = outer->next;
		while (inner != NULL)
		{
			if (outer->data == inner->data)
				return (0);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (-1);
}
