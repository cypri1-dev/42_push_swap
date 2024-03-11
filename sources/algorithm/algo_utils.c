/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:29:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 10:36:46 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	case_both_down(t_stack *tmp, t_stack **target, int *target_cost,
		t_cost *nbr)
{
	*target_cost = -1;
	if ((nbr->len_a - tmp->pos) > (nbr->len_b - (*target)->pos))
		*target_cost = (nbr->len_a - tmp->pos) + 1;
	else
		*target_cost = (nbr->len_b - (*target)->pos) + 1;
}

static void	case_both_up(t_stack *tmp, t_stack **target, int *target_cost)
{
	*target_cost = -1;
	if (tmp->pos >= (*target)->pos)
		*target_cost = tmp->pos + 1;
	else
		*target_cost = (*target)->pos + 1;
}

static void	find_best_diff(t_diff *nbr, t_stack *node, t_stack *tmp,
		t_stack **target)
{
	nbr->diff = node->value - tmp->value;
	if (nbr->best_diff == -1 || nbr->best_diff > nbr->diff)
	{
		nbr->best_diff = nbr->diff;
		*target = tmp;
	}
}

t_stack	*find_target(t_stack *node, t_stack **b)
{
	t_stack		*tmp;
	t_stack		*target;
	t_extremum	extrm_b;
	t_diff		nbr;

	tmp = *b;
	target = NULL;
	nbr.diff = -1;
	nbr.best_diff = -1;
	extrm_b.min = *b;
	extrm_b.max = *b;
	extrm_b = is_new_extremum(b, extrm_b);
	if (node->value > extrm_b.max->value || node->value < extrm_b.min->value)
		target = extrm_b.max;
	else
	{
		while (tmp)
		{
			if (node->value > tmp->value)
				find_best_diff(&nbr, node, tmp, &target);
			tmp = tmp->next;
		}
	}
	return (target);
}

t_stack	*calculate_cost(t_stack **a, t_stack **b)
{
	t_cost	nbr;
	t_stack	*tmp;

	t_stack(*target) = NULL;
	t_stack(*best_node) = NULL;
	tmp = *a;
	nbr.target_cost = 0;
	nbr.best_cost = INT_MAX;
	while (tmp)
	{
		calculate_size(a, b, &nbr);
		target = find_target(tmp, b);
		if (is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 1)
			case_both_up(tmp, &target, &nbr.target_cost);
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 0)
			case_both_down(tmp, &target, &nbr.target_cost, &nbr);
		else if (is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 0)
			nbr.target_cost = tmp->pos + (nbr.len_b - target->pos) + 1;
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 1)
			nbr.target_cost = target->pos + (nbr.len_a - tmp->pos) + 1;
		if (nbr.best_cost == INT_MAX || nbr.target_cost < nbr.best_cost)
			save_best_target(&nbr, &best_node, tmp, target);
		tmp = tmp->next;
	}
	return (best_node);
}
