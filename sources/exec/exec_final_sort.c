/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_final_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:35:18 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 11:25:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	last_moves(t_stack **a, t_stack *min)
{
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

static void	find_best_diff_2(t_diff *nbr, t_stack *node, t_stack *tmp,
		t_stack **target)
{
	nbr->diff = tmp->value - node->value;
	if (nbr->best_diff == -1 || nbr->best_diff > nbr->diff)
	{
		nbr->best_diff = nbr->diff;
		*target = tmp;
	}
}

static t_stack	*find_target_in_a(t_stack *node, t_stack **a)
{
	t_stack		*tmp;
	t_extremum	extrm_a;
	t_diff		nbr;

	t_stack(*target) = NULL;
	tmp = *a;
	extrm_a.min = *a;
	extrm_a.max = *a;
	extrm_a = is_new_extremum(a, extrm_a);
	nbr.best_diff = -1;
	if (node->value > extrm_a.max->value || node->value < extrm_a.min->value)
		target = extrm_a.min;
	else
	{
		while (tmp)
		{
			if (tmp->value > node->value)
			{
				if (nbr.best_diff == -1 || nbr.best_diff > nbr.diff)
					find_best_diff_2(&nbr, node, tmp, &target);
			}
			tmp = tmp->next;
		}
	}
	return (target);
}

void	final_sort(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*tmp_b;
	t_stack	*min;

	target = NULL;
	tmp_b = *b;
	min = NULL;
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
	last_moves(a, min);
}
