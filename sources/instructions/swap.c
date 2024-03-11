/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:13:13 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 08:43:45 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stack **a, int print)
{
	t_stack	*fisrt_node;
	t_stack	*second_node;

	if (*a != NULL && (*a)->next != NULL)
	{
		fisrt_node = *a;
		second_node = (*a)->next;
		fisrt_node->next = second_node->next;
		fisrt_node->previous = second_node;
		second_node->next = fisrt_node;
		second_node->previous = NULL;
		if (fisrt_node->next != NULL)
			fisrt_node->next->previous = fisrt_node;
		if (*a == fisrt_node)
			*a = second_node;
	}
	update_pos(*a);
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stack **b, int print)
{
	t_stack	*fisrt_node;
	t_stack	*second_node;

	if (*b != NULL && (*b)->next != NULL)
	{
		fisrt_node = *b;
		second_node = (*b)->next;
		fisrt_node->next = second_node->next;
		fisrt_node->previous = second_node;
		second_node->next = fisrt_node;
		second_node->previous = NULL;
		if (fisrt_node->next != NULL)
			fisrt_node->next->previous = fisrt_node;
		if (*b == fisrt_node)
			*b = second_node;
	}
	update_pos(*b);
	if (print)
		ft_printf("sb\n");
}

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	ft_printf("ss\n");
}
