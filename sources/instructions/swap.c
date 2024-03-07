/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:13:13 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/05 16:32:23 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_a(t_stack **a, int print)
{
    if (*a != NULL && (*a)->next != NULL)
    {
        t_stack *firstNode = *a;
        t_stack *secondNode = (*a)->next;

        firstNode->next = secondNode->next;
        firstNode->previous = secondNode;
        secondNode->next = firstNode;
        secondNode->previous = NULL;
        if (firstNode->next != NULL)
            firstNode->next->previous = firstNode;
        if (*a == firstNode)
            *a = secondNode;	
    }
    update_pos(*a);
    if(print)
        ft_printf("sa\n");
}

void swap_b(t_stack **b, int print)
{
    if (*b != NULL && (*b)->next != NULL)
    {
        t_stack *firstNode = *b;
        t_stack *secondNode = (*b)->next;

        firstNode->next = secondNode->next;
        firstNode->previous = secondNode;
        secondNode->next = firstNode;
        secondNode->previous = NULL;
        if (firstNode->next != NULL)
            firstNode->next->previous = firstNode;
        if (*b == firstNode)
            *b = secondNode;	
    }
    update_pos(*b);
    if(print)
        ft_printf("sb\n");
}
void swap_a_b(t_stack **a, t_stack **b)
{
    swap_a(a, 0);
    swap_b(b, 0);
    ft_printf("ss\n");
}