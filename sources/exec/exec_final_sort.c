/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_final_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:35:18 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/07 18:41:16 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack *find_target_in_a(t_stack *node, t_stack **a)
{
	t_stack *tmp = *a;
	t_stack *target = NULL;
	t_extremum extrm_a;

	extrm_a.min = *a;
	extrm_a.max = *a;
	extrm_a = is_new_extremum(a, extrm_a);
	int best_diff = -1;
	
	if (node->value > extrm_a.max->value || node->value < extrm_a.min->value)
		target = extrm_a.min;
	else
	{
		while (tmp)
		{
			if (tmp->value > node->value)
			{
				int diff = tmp->value - node->value;
				if (best_diff == -1 || best_diff > diff)
				{
					best_diff = diff;
					target = tmp;
				}
			}
			tmp = tmp->next;
		}
	}
	return target;
}
	
void final_sort(t_stack **a, t_stack **b)
{
	t_stack *target = NULL;
	t_stack *tmp_b = *b;
	t_stack *min = NULL;

	while (ft_lstsize(tmp_b) > 0)
	{
		target = find_target_in_a(tmp_b, a);
		if (is_up_or_down(a, target) == 1)
		{
			while (target->pos != 0)
				rotate_a(a, 1);
			push_a(a, b);
		}
		else if (is_up_or_down(a, target) == 0)
		{
			while (target->pos != 0)
				reverse_rotate_a(a, 1);
			push_a(a, b);
		}
		tmp_b = *b;
	}
	min = *a;
	t_stack *tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->value < min->value)
			min = tmp_a;
		tmp_a = tmp_a->next;
	}
	while ((*a)->value != min->value)
	{
		if (is_up_or_down(a, min) == 1)
			rotate_a(a, 1);
		else
			reverse_rotate_a(a, 1);
	}
}