/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:55:11 by ajacinto          #+#    #+#             */
/*   Updated: 2024/07/25 22:55:13 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_and_free(char **av)
{
	ft_free_split(av);
	ft_print_error();
}

void	validate_arg(char **av)
{
	int	i;
	int	j;

	av = ft_split(av[1], ' ');
	if (ft_atoi(av[0]) > INT_MAX || ft_atoi(av[0]) < INT_MIN)
		ft_error_and_free(&av[0]);
	j = -1;
	while (av[++j])
	{
		i = -1;
		while (av[j][++i])
		{
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (ft_isdigit(av[j][i]) &&
				(av[j][i + 1] == '+' || av[j][i + 1] == '-'))
				ft_error_and_free(av);
			if (!ft_isdigit(av[j][i]))
				ft_error_and_free(av);
		}
	}
	ft_free_split(av);
}

void	validate_arg2(int ac, char **av)
{
	int	i;
	int	current_arg;

	current_arg = 1;
	while (current_arg < ac)
	{
		i = 0;
		while (av[current_arg][i])
		{
			if (av[current_arg][i] == '+' || av[current_arg][i] == '-')
				i++;
			if (ft_isdigit(av[current_arg][i]) &&
				(av[current_arg][i + 1] == '+' ||
				av[current_arg][i + 1] == '-'))
				ft_print_error();
			if (!ft_isdigit(av[current_arg][i]))
				ft_print_error();
			i++;
		}
		current_arg++;
	}
}
