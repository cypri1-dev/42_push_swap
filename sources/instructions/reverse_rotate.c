/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:54:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 08:42:22 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stack **a, int print)
{
	t_stack	*last_node;

	last_node = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->previous->next = NULL;
	last_node->previous = NULL;
	last_node->next = *a;
	(*a)->previous = last_node;
	*a = last_node;
	update_pos(*a);
	if (print)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b, int print)
{
	t_stack	*last_node;

	last_node = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->previous->next = NULL;
	last_node->previous = NULL;
	last_node->next = *b;
	(*b)->previous = last_node;
	*b = last_node;
	update_pos(*b);
	if (print)
		ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}
