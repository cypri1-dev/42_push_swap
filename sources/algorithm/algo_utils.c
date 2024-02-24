/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:29:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/22 19:53:37 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *find_target(t_stack *node, t_stack **b, t_extremum extrm)
{
    t_stack *tmp = *b;
    t_stack *targetNode = NULL;

    while (tmp)
    {
        if (node->value > extrm.max->value || node->value < extrm.min->value)
        {
            targetNode = extrm.max;
            break;
        }

        if (tmp->next != NULL && node->value < tmp->value && node->value > tmp->next->value)
        {
            targetNode = tmp->next;
            break;
        }

        if (tmp->next != NULL)
            tmp = tmp->next;
        else
            break; // Sortir de la boucle si tmp->next est NULL
    }

    return targetNode;
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
    if (node->pos <= (len / 2))
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


t_stack *calculate_cost(t_stack **a, t_stack **b, t_extremum extrm)
{
	int target_cost;
	int best_cost;
	int len_a;
	int len_b;
	t_stack *target = NULL;
	t_stack *best_node = NULL;
	t_stack *tmp = *a;
	//t_stack *tmp2 = *b;
	
	target_cost = 0;
	best_cost = 0;
	while(tmp)
	{
		len_a = ft_lstsize(*a);
		len_b = ft_lstsize(*b);
		target = find_target(tmp, b, extrm);
				
		if(is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 1)
		{
			printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			if (tmp->pos >= target->pos)
				target_cost = (target->pos + (tmp->pos - target->pos) + 1);
			else
				target_cost = (tmp->pos + (target->pos - tmp->pos) + 1);
		}
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 0)
		{
			printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			if (tmp->pos > target->pos)
				target_cost = (len_a - tmp->pos) + ((len_b - target->pos) - (len_a - tmp->pos) + 1);
			else
				target_cost = (len_b - target->pos) + ((len_a - tmp->pos) - (len_b - target->pos) + 1);
		}
		else if (is_up_or_down(a, tmp) == 1 && is_up_or_down(b, target) == 0)
		{
			printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			target_cost = tmp->pos + (len_b - target->pos) + 1;
		}
		else if (is_up_or_down(a, tmp) == 0 && is_up_or_down(b, target) == 1)
		{
			printf("\ntmp->pos = %d || target->pos = %d || len_a = %d || len_b = %d\n", tmp->pos, target->pos, len_a, len_b);
			target_cost = target->pos + (len_a - tmp->pos) + 1;
		}	
		printf("\ncost to push : [%d]\n", target_cost);
		if(best_cost == 0 || target_cost < best_cost)
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
	exit_error(sorted, "OK", a, args);
}
t_extremum	is_new_extremum(t_stack **b, t_extremum extrm)
{
	t_stack *tmp;
	
	tmp = *b;
	while (tmp && tmp->next)
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