/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:33:54 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/05 16:31:59 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(enum e_state i, t_stack *a, char **args)
{
	if (i == env_error || i == arg_missing || i == wrong_input || i == arg_empty)
	{	
		ft_printf("Error\n");
		exit(1);
	}
	if (i == double_nb || i == overflow)
	{
		free_tab(args);
		ft_lstclear(&a);
		ft_printf("Error\n");
		exit(1);
	}
	if (i == sorted)
	{
		free_tab(args);
		ft_lstclear(&a);
		ft_printf("OK\n");
		exit(0);
	}
	
}