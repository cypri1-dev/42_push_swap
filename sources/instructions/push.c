/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:13:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/21 17:28:53 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack *topB;
	
	if (*b == NULL)
		return ;
	topB = *b;
	*b = topB->next;
	if (*a != NULL)
	{
		topB->next = *a;
		(*a)->previous = topB;
	}
	else
		topB->next = NULL;
	topB->previous = NULL;
	*a = topB;
	update_pos(*a);
	update_pos(*b);
	printf("pa\n");
}
void	push_b(t_stack **a, t_stack **b)
{
	t_stack *topA;
	
	if (*a == NULL)
		return ;
	topA = *a;
	*a = topA->next;
	if (*b != NULL)
	{
		topA->next = *b;
		(*b)->previous = topA;
	}
	else
		topA->next = NULL;
	topA->previous = NULL;
	*b = topA;
	update_pos(*a);
	update_pos(*b);
	printf("pb\n");
}