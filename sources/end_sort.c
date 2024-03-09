/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:33:54 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/09 18:20:06 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(enum e_state i, t_stack *a, char **args)
{
	if (i == wrong_input || i == double_nb || i == overflow)
	{
		if(args != NULL)
			free_tab(args);
		if (a != NULL)
			ft_lstclear(&a);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (i == arg_missing || i == sorted || i == arg_empty)
	{
		if(args != NULL)
			free_tab(args);
		if (a != NULL)
			ft_lstclear(&a);
		exit(1);
	}
}