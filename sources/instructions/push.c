/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:13:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 08:43:13 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (*b == NULL)
		return ;
	top_b = *b;
	*b = top_b->next;
	if (*a != NULL)
	{
		top_b->next = *a;
		(*a)->previous = top_b;
	}
	else
		top_b->next = NULL;
	top_b->previous = NULL;
	*a = top_b;
	update_pos(*a);
	update_pos(*b);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (*a == NULL)
		return ;
	top_a = *a;
	*a = top_a->next;
	if (*b != NULL)
	{
		top_a->next = *b;
		(*b)->previous = top_a;
	}
	else
		top_a->next = NULL;
	top_a->previous = NULL;
	*b = top_a;
	update_pos(*a);
	update_pos(*b);
	ft_printf("pb\n");
}
