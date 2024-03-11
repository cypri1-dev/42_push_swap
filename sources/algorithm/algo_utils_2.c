/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:49:31 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 10:38:47 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	save_best_target(t_cost *nbr, t_stack **best_node, t_stack *tmp,
		t_stack *target)
{
	nbr->best_cost = nbr->target_cost;
	*best_node = tmp;
	(*best_node)->target = target;
}

void	calculate_size(t_stack **a, t_stack **b, t_cost *nbr)
{
	nbr->len_a = ft_lstsize(*a);
	nbr->len_b = ft_lstsize(*b);
}

void	sort_worst_case(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, 1);
	push_a(a, b);
	rotate_a(a, 1);
	rotate_a(a, 1);
}

int	is_up_or_down(t_stack **lst, t_stack *node)
{
	t_stack	*tmp;
	int		len;

	tmp = *lst;
	len = ft_lstsize(tmp);
	if (node == NULL || *lst == NULL)
		return (-1);
	if (node->pos < (len / 2))
		return (1);
	else
		return (0);
}

t_extremum	is_new_extremum(t_stack **b, t_extremum extrm)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->value > extrm.max->value)
		{
			extrm.max = tmp;
			extrm.pos = tmp->pos;
		}
		else if (tmp->value < extrm.min->value)
			extrm.min = tmp;
		tmp = tmp->next;
	}
	return (extrm);
}
