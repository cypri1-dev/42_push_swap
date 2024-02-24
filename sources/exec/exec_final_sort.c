/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_final_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:35:18 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/22 21:04:40 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack *find_target_a(t_stack **a, t_stack *node)
{
	t_stack *tmp = *a;
	t_stack *target = NULL;
	
	while(tmp)
	{
		if (node->value < tmp->value && (node->value > node->previous->value || node->previous == NULL))
			target = tmp->value;
		tmp = tmp->next;
	}
	return(target);
}

void	final_sort(t_stack **a, t_stack **b)
{
	t_extremum extrm;
	t_stack *tmp = *b;
	t_stack *target = NULL;

	while(ft_lstsize(*b) != 0)
	{
		target = find_target_a(a, tmp);
		while (target->pos != 0)
	}
}