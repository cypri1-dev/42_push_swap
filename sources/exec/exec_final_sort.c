/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_final_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:35:18 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 14:18:02 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_target_ah(t_stack **a, t_stack *node, t_stack **target)
{
	t_stack	*tmp;
	int		best_diff;
	int		diff;

	tmp = *a;
	best_diff = -1;
	while (tmp)
	{
		if (tmp->value > node->value)
		{
			diff = tmp->value - node->value;
			if (best_diff == -1 || best_diff > diff)
			{
				best_diff = diff;
				*target = tmp;
			}
		}
		tmp = tmp->next;
	}
}

static t_stack	*find_target_in_a(t_stack *node, t_stack **a)
{
	t_stack		*target;
	t_extremum	extrm_a;

	target = NULL;
	extrm_a.min = *a;
	extrm_a.max = *a;
	extrm_a = is_new_extremum(a, extrm_a);
	if (node->value > extrm_a.max->value || node->value < extrm_a.min->value)
		target = extrm_a.min;
	else
	{
		find_target_ah(a, node, &target);
	}
	return (target);
}

static void	move_min_to_top(t_stack **a)
{
	t_stack	*min;
	t_stack	*tmp_a;

	tmp_a = *a;
	min = *a;
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

void	final_sort(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*tmp_b;

	target = NULL;
	tmp_b = *b;
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
	move_min_to_top(a);
}
