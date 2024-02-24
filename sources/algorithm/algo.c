/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/22 20:53:26 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_extremum(t_extremum *extremum)
{
	if(!extremum)
		return;
	extremum->pos = 0;
	extremum->min = NULL;
	extremum->max = NULL;
}

void	sort_two(t_stack **a)
{
	t_stack *tmp = *a;

	if (tmp->value > tmp->next->value)
		swap_a(a, 1);
}

void	sort_three(t_stack **a)
{
	t_stack *tmp = *a;
	
	if (tmp->value < tmp->next->next->value && tmp->next->value > tmp->next->next->value)
	{
		reverse_rotate_a(a, 1);
		swap_a(a, 1);
	}
	else if (tmp->value > tmp->next->value && tmp->value < tmp->next->next->value)
		swap_a(a, 1);
	else if (tmp->value < tmp->next->value && tmp->value > tmp->next->next->value)
		reverse_rotate_a(a, 1);
	else if (tmp->value > tmp->next->value && tmp->next->value < tmp->next->next->value)
		rotate_a(a, 1);
	else if (tmp->value > tmp->next->value && tmp->next->value > tmp->next->next->value)
	{
		rotate_a(a, 1);
		swap_a(a, 1);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int min;
	int max;
	
	push_b(a, b);
	sort_three(a);
	min = (*a)->value;
	max = (*a)->next->next->value;
	if ((*b)->value < min)
		push_a(a, b);
	else if ((*b)->value > max)
	{
		push_a(a, b);
		rotate_a(a, 1);
	}
	else if ((*b)->value > min && (*b)->value < (*a)->next->value)
	{
		rotate_a(a, 1);
		push_a(a, b);
		reverse_rotate_a(a, 1);
	}
	else if ((*b)->value > (*a)->next->value && (*b)->value < max)
	{
		reverse_rotate_a(a, 1);
		push_a(a, b);
		rotate_a(a, 1);
		rotate_a(a, 1);
	}
}
void	sort_big_list(t_stack **a, t_stack **b)
{ 
	t_extremum extrm;
	t_stack *best_element;
	
	push_b(a, b);
	push_b(a, b);
	if ((*b)->value > (*b)->next->value)
	{
		extrm.max = (*b);
		extrm.min = (*b)->next;
	}
	else
	{
		extrm.max = (*b)->next;
		extrm.min = (*b);
	}
	//printf("\nmin value : [%d]\nmax value : [%d]\n", extrm.min, extrm.max);
	while (ft_lstsize(*a) > 3)
	{
		extrm = is_new_extremum(b, extrm);
		best_element = calculate_cost(a, b, extrm);
		printf("\nNext to push is [%d]\n", best_element->value);
		move_to_pos(a, b, best_element);
		// if(best_element != NULL)
		// 	printf("\nnode to push --> value : [%d] || pos : [%d]\n\n", best_element->value, best_element->pos);
		// printf("\nnew min value in B: [%d]\nnew max value in B: [%d]\n", extrm.min, extrm.max);
		// printf("\n[%d] (1 for UP - 0 for DOWN)\n", is_up_or_down(a, best_element));
	}
	sort_three(a);
	//final_sort(a, b);
}