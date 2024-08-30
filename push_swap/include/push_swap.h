/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:34:00 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/23 23:34:02 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct node_list
{
	int					data;
	struct node_list	*next;
}t_node;

t_node	*create_node(int value);
void	ft_print_error(void);
void	ft_cleanm(t_node **head);
void	ft_free_split(char **split);
void	validate_qty_args(t_node **head);
void	validate_arg(char **av);
void	put_on_top_b(t_node **head, int value);
void	put_on_top(t_node **head, int value);
void	ft_ordering_less_5(t_node **head);
void	ft_ordering_more_5(t_node **head);
void	ft_ordering(t_node **head);
void	sa(t_node **head);
void	ra(t_node **head);
void	rb(t_node **head);
void	rra(t_node **head);
void	rrb(t_node **head);
void	validate_arg2(int ac, char **av);
void	ft_sort(t_node **head);
void	add_on_stack_arg(char **av, t_node **head);
void	add_on_stack_arg2(char **av, t_node **head, int ac);
void	add_begin(t_node **head, int value);
void	print_list(t_node *head);
int		calculate_cos(t_node *head, int value);
int		ft_smallest(t_node *head);
int		ft_is_sorted(t_node *head);
int		ft_greatest(t_node *head);
int		ft_count_node(t_node *head);
int		ft_target(t_node *stack_a, int target_value);
int		pa(t_node **head);
int		pb(t_node **head);
int		ft_find_position(t_node *head, int value);
int		find_cheapest_value(t_node *b, t_node *a);
int		find_equal_values(t_node *head);

#endif
