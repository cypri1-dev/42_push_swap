/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:27:02 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 20:48:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static t_stacks	init_checker_arg(char *str)
{
	t_stacks	stacks;
	char		**args;
	int			i;

	i = 0;
	stacks.a = NULL;
	stacks.b = NULL;
	args = ft_split(str, ' ');
	if (!args)
		return (stacks);
	if (!args[0])
		exit_error(overflow, stacks.a, args);
	while (args[i])
	{
		ft_lstadd_back(&stacks.a, ft_lstnew(ft_atoi(args[i]), i));
		i++;
	}
	ft_check(stacks.a, args);
	return (stacks);
}

static t_stacks	init_checker_multi_arg(int argc, char **argv)
{
	t_stacks	stacks;
	int			i;

	(void)argc;
	stacks.a = NULL;
	stacks.b = NULL;
	i = 0;
	while (argv[++i])
		ft_lstadd_back(&stacks.a, ft_lstnew(ft_atoi(argv[i]), i));
	return (stacks);
}

int	check_is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_part_2(t_stacks *stacks, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check_exec(stacks, line);
		free(tmp);
	}
	if (stacks->b)
		write(2, "KO\n", 3);
	else if (!check_is_sorted(stacks->a))
		write(2, "KO\n", 4);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_stacks	stacks;
	char		*line;

	i = 1;
	first_check(envp, argc);
	if (argc == 2)
	{
		pars_one_arg(argv[1]);
		stacks = init_checker_arg(argv[1]);
	}
	if (argc > 2)
	{
		while (argv[i])
			pars_one_arg(argv[i++]);
		stacks = init_checker_multi_arg(argc, argv);
	}
	line = get_next_line(0);
	return_checker(line, stacks);
	ft_lstclear(&stacks.a);
	ft_lstclear(&stacks.b);
	return (0);
}
