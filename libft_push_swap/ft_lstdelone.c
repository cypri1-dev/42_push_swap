/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:57:19 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 07:53:47 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	lst->value = 0;
	lst->pos = 0;
	lst->cost = 0;
	lst->previous = NULL;
	lst->target = NULL;
	lst->next = NULL;
	free(lst);
}
