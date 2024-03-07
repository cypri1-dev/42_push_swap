/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:29:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/07 17:56:46 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void ft_print_list(t_stack **list)
// {
// 	t_stack *tmp;

// 	tmp = *list;
// 	while (tmp)
// 	{
// 		printf("value : [%d] || pos : [%d]\n", tmp->value, tmp->pos);
// 		tmp = tmp->next;
// 	}
// }

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

	// printf("node = %d\n", node->value);
	if (node->value > extrm_b.max->value || node->value < extrm_b.min->value)
		target = extrm_b.max;
	else
	{
		while (tmp)
		{
			if(node->value > tmp->value)
			{
				// printf("\nnode in a : %d || node in b : %d\n", node->value, tmp->value);
				diff = node->value - tmp->value;
				// printf ("\nDiff --> [%d]\n", diff);
				if (best_diff == -1 || best_diff > diff)
				{
					best_diff = diff;
					target = tmp;
				}
			}
			tmp = tmp->next;
		}
		// printf("\nBest diff --> %d\n", best_diff);
	}
	return target;
}


int is_up_or_down(t_stack **lst, t_stack *node)
{
    t_stack *tmp = *lst;
    int len = ft_lstsize(tmp);
	
    if (node == NULL || *lst == NULL)
    {
        // Gérer le cas où le pointeur node est nul ou la liste est vide
        return(-1); // Valeur de retour spéciale pour indiquer une erreur ou un cas indéfini
    }
    if (node->pos < (len / 2))
    {
        //printf("node number = %d - 1\n", node->value);
        return 1;
    }
    else
    {
        //printf("node number = %d - 0\n", node->value);
        return 0;
    }
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
		// if (!target)
		// 	printf ("NO TARGET\n");
		if(is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 1)
		{
			// printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			if (tmp->pos >= target->pos)
				target_cost = tmp->pos + 1;
			else
				target_cost = target->pos + 1;
		}
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 0)
		{
			// printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			if ((len_a - tmp->pos) > (len_b - target->pos))
				target_cost = (len_a - tmp->pos) + 1;
			else
				target_cost = (len_b - target->pos) + 1;
		}
		else if (is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 0)
		{
			// printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			target_cost = tmp->pos + (len_b - target->pos) + 1;
		}
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 1)
		{
			// printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			target_cost = target->pos + (len_a - tmp->pos) + 1;
		}	
		// printf("\ncost to push : [%d]\n", target_cost);
		// printf("\n its target is --> %d\n", target->value);
		// ft_print_list(a);
		// printf ("---------\n");
		// ft_print_list(b);
		// printf ("----------------------------------\n");
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