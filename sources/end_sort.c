/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:33:54 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/20 15:36:45 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(enum e_state i, char *message, t_stack *a, char **args)
{
	if (i == env_error || i == arg_missing || i == wrong_input || i == arg_empty)
	{	
		ft_printf(RED "Error\n%s\n" ENDC, message);
		exit(1);
	}
	if (i == double_nb || i == overflow)
	{
		free_tab(args);
		ft_lstclear(&a);
		ft_printf(RED "Error\n%s\n" ENDC, message);
		exit(1);
	}
	if (i == sorted)
	{
		free_tab(args);
		ft_lstclear(&a);
		ft_printf(GREEN "%s\n" ENDC, message);
		exit(0);
	}
	
}