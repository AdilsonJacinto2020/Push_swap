/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:14:27 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/30 18:14:28 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_target(t_node *stack_a, int target_value)
{
	int	closest;
	int	greatest;

	closest = INT_MAX;
	greatest = ft_smallest(stack_a);
	while (stack_a != NULL)
	{
		if (stack_a->data > target_value && stack_a->data < closest)
			closest = stack_a->data;
		stack_a = stack_a->next;
	}
	if (closest == INT_MAX)
		return (greatest);
	return (closest);
}

int	calculate_cos(t_node *head, int value)
{
	int	cost;
	int	len;
	int	pos;

	pos = ft_find_position(head, value);
	len = ft_count_node(head);
	if (pos <= len / 2)
		cost = pos;
	else
		cost = len - pos;
	return (cost);
}

int	find_cheapest_value(t_node *b, t_node *a)
{
	t_node	*tmp_b;
	int		cost;
	int		cheapest;
	int		cost_t;
	int		target;

	cost = INT_MAX;
	tmp_b = b;
	while (tmp_b)
	{
		target = ft_target(a, tmp_b->data);
		cost_t = calculate_cos(a, target) + calculate_cos(b, tmp_b->data);
		if (cost_t < cost)
		{
			cost = cost_t;
			cheapest = tmp_b->data;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}

void	put_on_top_b(t_node **head, int value)
{
	int	cost;
	int	len;
	int	pos;

	len = ft_count_node(*head);
	pos = ft_find_position(*head, value);
	if (pos <= len / 2)
	{
		cost = pos;
		while (cost--)
			rb(head);
	}
	else
	{
		cost = len - pos;
		while (cost--)
			rrb(head);
	}
}

void	put_on_top(t_node **head, int value)
{
	int	cost;
	int	len;
	int	pos;

	len = ft_count_node(*head);
	pos = ft_find_position(*head, value);
	if (pos <= len / 2)
	{
		cost = pos;
		while (cost--)
			ra(head);
	}
	else
	{
		cost = len - pos;
		while (cost--)
			rra(head);
	}
}
