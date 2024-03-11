/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:00:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 11:29:35 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check(t_stack *a, char **args)
{
	check_overflow(a, args);
	check_double(a, args);
	is_sorted(a, args);
	free_tab(args);
}

void	ft_algo(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else
		sort_big_list(a, b);
}

void	is_sorted(t_stack *a, char **args)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return ;
		tmp = tmp->next;
	}
	exit_error(sorted, a, args);
}
