/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:25:28 by ajacinto          #+#    #+#             */
/*   Updated: 2024/08/02 19:25:32 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	validate_qty_args(t_node **head)
{
	if (find_equal_values(*head) == 0)
	{
		ft_cleanm(head);
		ft_print_error();
	}
	if (ft_is_sorted(*head) == 0)
	{
		ft_cleanm(head);
		exit(EXIT_FAILURE);
	}
	if (ft_count_node(*head) == 2)
		sa(head);
	else if (ft_count_node(*head) == 3)
		ft_ordering(head);
	else if (ft_count_node(*head) >= 4 && ft_count_node(*head) <= 5)
		ft_ordering_less_5(head);
	else if (ft_count_node(*head) > 5)
		ft_ordering_more_5(head);
}

void	ft_ordering(t_node **head)
{
	if ((*head)->data == ft_greatest(*head))
		ra(head);
	if ((*head)->next->data == ft_greatest(*head))
		rra(head);
	if ((*head)->data > (*head)->next->data)
		sa(head);
}

void	ft_ordering_less_5(t_node **head)
{
	t_node	*b;
	int		popped;

	b = NULL;
	while (ft_count_node(*head) > 3)
	{
		put_on_top(head, ft_smallest(*head));
		popped = pb(head);
		add_begin(&b, popped);
	}
	ft_ordering(head);
	while (ft_count_node(b) > 0)
	{
		popped = pa(&b);
		add_begin(head, popped);
	}
}

void	ft_ordering_more_5(t_node **head)
{
	t_node	*b;
	int		popped;
	int		cheapest_b;
	int		target;

	b = NULL;
	while (ft_count_node(*head) > 5)
	{
		popped = pb(head);
		add_begin(&b, popped);
	}
	ft_ordering_less_5(head);
	while (ft_count_node(b) > 0)
	{
		cheapest_b = find_cheapest_value(b, *head);
		target = ft_target(*head, cheapest_b);
		put_on_top_b(&b, cheapest_b);
		put_on_top(head, target);
		popped = pa(&b);
		add_begin(head, popped);
	}
	put_on_top(head, ft_smallest(*head));
}
