/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:29:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/07 18:40:31 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *find_target(t_stack *node, t_stack **b)
{
    t_stack *tmp = *b;
    t_stack *target = NULL;
	t_extremum extrm_b;

	int diff = -1;
	int best_diff = -1;
	extrm_b.min = *b;
	extrm_b.max = *b;
	extrm_b = is_new_extremum(b, extrm_b);

	if (node->value > extrm_b.max->value || node->value < extrm_b.min->value)
		target = extrm_b.max;
	else
	{
		while (tmp)
		{
			if(node->value > tmp->value)
			{
				diff = node->value - tmp->value;
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


int is_up_or_down(t_stack **lst, t_stack *node)
{
    t_stack *tmp = *lst;
    int len = ft_lstsize(tmp);
	
    if (node == NULL || *lst == NULL)
        return(-1);
    if (node->pos < (len / 2))
        return 1;
    else
        return 0;
}


t_stack *calculate_cost(t_stack **a, t_stack **b)
{
	int target_cost;
	int best_cost;
	int len_a;
	int len_b;
	t_stack *target = NULL;
	t_stack *best_node = NULL;
	t_stack *tmp = *a;
	
	target_cost = 0;
	best_cost = INT_MAX;
	while(tmp)
	{
		len_a = ft_lstsize(*a);
		len_b = ft_lstsize(*b);
		target = find_target(tmp, b);

		if(is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 1)
		{
			if (tmp->pos >= target->pos)
				target_cost = tmp->pos + 1;
			else
				target_cost = target->pos + 1;
		}
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 0)
		{
			if ((len_a - tmp->pos) > (len_b - target->pos))
				target_cost = (len_a - tmp->pos) + 1;
			else
				target_cost = (len_b - target->pos) + 1;
		}
		else if (is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 0)
			target_cost = tmp->pos + (len_b - target->pos) + 1;
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 1)
			target_cost = target->pos + (len_a - tmp->pos) + 1;
		if(best_cost == INT_MAX || target_cost < best_cost)
		{	
			best_cost = target_cost;
			best_node = tmp;
			best_node->target = target;
		}
		tmp = tmp->next;
	}
	return(best_node);
}

void	is_sorted(t_stack *a, char **args)
{
	t_stack *tmp = a;

	while (tmp && tmp->next)
	{
		if(tmp->value > tmp->next->value)
			return;
		tmp = tmp->next;
	}
	exit_error(sorted, a, args);
}

t_extremum	is_new_extremum(t_stack **b, t_extremum extrm)
{
	t_stack *tmp;
	
	tmp = *b;
	while (tmp)
	{
		if (tmp->value > extrm.max->value)
		{
			extrm.max = tmp;
			extrm.pos = tmp->pos;
		}
		else if (tmp->value < extrm.min->value)
			extrm.min = tmp;	
		tmp = tmp->next;
	}
	return(extrm);
}