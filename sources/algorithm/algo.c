/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:35:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 20:19:54 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_extremum(t_extremum *extremum)
{
	if (!extremum)
		return ;
	extremum->pos = 0;
	extremum->min = NULL;
	extremum->max = NULL;
}

void	sort_two(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (tmp->value > tmp->next->value)
		swap_a(a, 1);
}

void	sort_three(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (tmp->value < tmp->next->next->value
		&& tmp->next->value > tmp->next->next->value)
	{
		reverse_rotate_a(a, 1);
		swap_a(a, 1);
	}
	else if (tmp->value > tmp->next->value
		&& tmp->value < tmp->next->next->value)
		swap_a(a, 1);
	else if (tmp->value < tmp->next->value
		&& tmp->value > tmp->next->next->value)
		reverse_rotate_a(a, 1);
	else if (tmp->value > tmp->next->value
		&& tmp->next->value < tmp->next->next->value)
		rotate_a(a, 1);
	else if (tmp->value > tmp->next->value
		&& tmp->next->value > tmp->next->next->value)
	{
		rotate_a(a, 1);
		swap_a(a, 1);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	max;

	push_b(a, b, 1);
	sort_three(a);
	min = (*a)->value;
	max = (*a)->next->next->value;
	if ((*b)->value < min)
		push_a(a, b, 1);
	else if ((*b)->value > max)
	{
		push_a(a, b, 1);
		rotate_a(a, 1);
	}
	else if ((*b)->value > min && (*b)->value < (*a)->next->value)
	{
		rotate_a(a, 1);
		push_a(a, b, 1);
		reverse_rotate_a(a, 1);
	}
	else if ((*b)->value > (*a)->next->value && (*b)->value < max)
		sort_worst_case(a, b);
}

void	sort_big_list(t_stack **a, t_stack **b)
{
	t_extremum	extrm;
	t_stack		*best_element;

	push_b(a, b, 1);
	push_b(a, b, 1);
	if ((*b)->value > (*b)->next->value)
	{
		extrm.max = (*b);
		extrm.min = (*b)->next;
	}
	else
	{
		extrm.max = (*b)->next;
		extrm.min = (*b);
		swap_b(b, 1);
	}
	while (ft_lstsize(*a) > 3)
	{
		extrm = is_new_extremum(b, extrm);
		best_element = calculate_cost(a, b);
		move_to_pos(a, b, best_element);
	}
	sort_three(a);
	final_sort(a, b);
}
