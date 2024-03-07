/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:54:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/05 17:05:10 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void reverse_rotate_a(t_stack **a, int print) 
{
    t_stack *lastNode = *a;
	
    if (*a == NULL || (*a)->next == NULL) 
        return;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->previous->next = NULL;
    lastNode->previous = NULL;
    lastNode->next = *a;
    (*a)->previous = lastNode;
    *a = lastNode;
	update_pos(*a);
	if(print)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **b, int print) 
{
    t_stack *lastNode = *b;
	
    if (*b == NULL || (*b)->next == NULL) 
        return;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->previous->next = NULL;
    lastNode->previous = NULL;
    lastNode->next = *b;
    (*b)->previous = lastNode;
    *b = lastNode;
	update_pos(*b);
	if(print)
		ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	// update_pos(*a);
	// update_pos(*b);
	ft_printf("rrr\n");
}