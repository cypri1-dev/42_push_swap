/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:05:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/19 11:02:21 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_a(t_stack **a, int print)
{
	t_stack *lastNode;
	
	if (*a == NULL || (*a)->next == NULL)
		return ;
	lastNode = *a;
	while(lastNode->next != NULL)
		lastNode = lastNode->next;
	lastNode->next = *a;
	(*a)->previous = lastNode;
	*a = (*a)->next;
	(*a)->previous = NULL;
	lastNode->next->next = NULL;
	update_pos(*a);
	if(print)
		printf("ra\n");
}
void	rotate_b(t_stack **b, int print)
{
	t_stack *lastNode;
	
	if (*b == NULL || (*b)->next == NULL)
		return ;
	lastNode = *b;
	while(lastNode->next != NULL)
		lastNode = lastNode->next;
	lastNode->next = *b;
	(*b)->previous = lastNode;
	*b = (*b)->next;
	(*b)->previous = NULL;
	lastNode->next->next = NULL;
	update_pos(*b);
	if(print)
		printf("rb\n");
}
void	rotate_a_b(t_stack **a, t_stack **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	printf("rr\n");
}