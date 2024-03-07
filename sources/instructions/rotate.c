/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/07 18:44:51 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stack **a, int print)
{
	t_stack *last_node;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	last_node = *a;
	while(last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *a;
	(*a)->previous = last_node;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last_node->next->next = NULL;
	update_pos(*a);
	if(print)
		ft_printf("ra\n");
}
void	rotate_b(t_stack **b, int print)
{
	t_stack *last_node;
	
	if (*b == NULL || (*b)->next == NULL)
		return ;
	last_node = *b;
	while(last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *b;
	(*b)->previous = last_node;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last_node->next->next = NULL;
	update_pos(*b);
	if(print)
		ft_printf("rb\n");
}
void	rotate_a_b(t_stack **a, t_stack **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	ft_printf("rr\n");
}