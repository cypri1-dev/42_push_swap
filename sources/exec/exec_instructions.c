/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:05:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/07 18:42:43 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	a_down_and_b_top_median(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->pos != 0)
		reverse_rotate_a(a, 1);
	while (node->target->pos != 0)
		rotate_b(b, 1);
	push_b(a, b);
}

static void	a_top_and_b_down_median(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->pos != 0)
		rotate_a(a, 1);
	while (node->target->pos != 0)
		reverse_rotate_b(b, 1);
	push_b(a, b);
}

static void	both_down_median(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->pos != 0 && node->target->pos != 0)
		reverse_rotate_a_b(a, b);
	while (node->pos != 0)
		reverse_rotate_a(a, 1);
	while (node->target->pos != 0)
		reverse_rotate_b(b, 1);
	push_b(a, b);
}

static void	both_top_median(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->pos != 0 && node->target->pos != 0)
		rotate_a_b(a, b);
	while (node->pos != 0)
		rotate_a(a, 1);
	while (node->target->pos != 0)
		rotate_b(b, 1);
	push_b(a, b);
}

void	move_to_pos(t_stack **a, t_stack **b, t_stack *node)
{
	if (is_up_or_down(a, node) == 1 && is_up_or_down(b, node->target) == 1)
		both_top_median(a, b, node);
	else if (is_up_or_down(a, node) == 0 && is_up_or_down(b, node->target) == 0)
		both_down_median(a, b, node);
	else if (is_up_or_down(a, node) == 1 && is_up_or_down(b, node->target) == 0)
		a_top_and_b_down_median(a, b, node);
	else if (is_up_or_down(a, node) == 0 && is_up_or_down(b, node->target) == 1)
		a_down_and_b_top_median(a, b, node);
}
