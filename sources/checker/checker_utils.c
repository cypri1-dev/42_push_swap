/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:47:49 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 20:43:08 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	check_exec_2(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		reverse_rotate_a(a, 2);
	else if (line[2] == 'b')
		reverse_rotate_b(b, 2);
	else if (line[2] == 'r')
		reverse_rotate_a_b(a, b, 2);
}

char	*check_exec(t_stacks *stacks, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_a(&stacks->a, 2);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_b(&stacks->b, 2);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_a(&stacks->a, &stacks->b, 2);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_b(&stacks->a, &stacks->b, 2);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_a(&stacks->a, 2);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_b(&stacks->b, 2);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_exec_2(&stacks->a, &stacks->b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rotate_a_b(&stacks->a, &stacks->b, 2);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		swap_a_b(&stacks->a, &stacks->b, 2);
	else
		exit_error(wrong_input, NULL, NULL);
	return (get_next_line(0));
}

void	first_check(char **envp, int argc)
{
	if (!check_env(envp))
		exit_error(env_error, NULL, NULL);
	if (argc < 2)
		exit_error(arg_missing, NULL, NULL);
}

void	return_checker(char *line, t_stacks stacks)
{
	if (!line && !check_is_sorted(stacks.a))
		write(2, "KO\n", 4);
	else if (!line && check_is_sorted(stacks.a))
		write(1, "OK\n", 3);
	else
		check_part_2(&stacks, line);
}
