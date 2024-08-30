/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:44:18 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/24 13:44:22 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void	add_begin(t_node **head, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	new_node->next = *head;
	*head = new_node;
}

void	add_on_stack_arg(char **av, t_node **head)
{
	int		i;
	long	value;

	i = 0;
	av = ft_split(av[1], ' ');
	while (av[i])
		i++;
	if (i == 1)
	{
		ft_free_split(av);
		exit(0);
	}
	while (i--)
	{
		value = ft_atoi(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_free_split(av);
			ft_cleanm(head);
			ft_print_error();
		}
		else
			add_begin(head, value);
	}
	ft_free_split(av);
}

void	add_on_stack_arg2(char **av, t_node **head, int ac)
{
	int		current_arg;
	long	value;

	current_arg = ac - 1;
	if (current_arg == 1)
		exit(EXIT_FAILURE);
	while (current_arg)
	{
		value = ft_atoi(av[current_arg]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_cleanm(head);
			ft_print_error();
		}
		else
			add_begin(head, value);
		current_arg--;
	}
}

void	ft_cleanm(t_node **head)
{
	t_node	*to_remove;

	while (*head)
	{
		to_remove = *head;
		*head = (*head)->next;
		free(to_remove);
	}
	*head = NULL;
}
