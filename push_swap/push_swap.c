/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:06:24 by ajacinto          #+#    #+#             */
/*   Updated: 2024/08/21 01:56:06 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	val(int ac, char **av)
{
	int	i;

	i = 1;
	while (i <= ac - 1)
	{
		if (ft_strchr(av[i], 32))
			ft_print_error();
		i++;
	}
}

void	val1(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i] && ((av[j][i] == ' ' || av[j][i] == '\t' )))
			i++;
		if (!av[j][i])
			ft_print_error();
		j++;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;

	a = NULL;
	if (ac <= 1)
		return (0);
	else if (ac == 2)
	{
		val1(av);
		validate_arg(av);
		add_on_stack_arg(av, &a);
	}
	else if (ac > 2)
	{
		val(ac, av);
		validate_arg2(ac, av);
		add_on_stack_arg2(av, &a, ac);
	}
	validate_qty_args(&a);
	ft_cleanm(&a);
	return (0);
}
