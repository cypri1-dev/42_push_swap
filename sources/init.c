/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:15 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 14:45:22 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

char	**free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

void	init_arg(char *str)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	args = ft_split(str, ' ');
	if (!args)
		return ;
	if (!args[0])
		exit_error(overflow, a, args);
	while (args[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(args[i]), i));
		i++;
	}
	ft_check(a, args);
	ft_algo(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}

void	init_multi_arg(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		i;
	int		j;

	i = 1;
	j = 0;
	a = NULL;
	b = NULL;
	args = malloc(sizeof(char *) * (argc));
	if (!args)
		return ;
	while (argv[i])
		args[j++] = ft_strdup(argv[i++]);
	args[j] = NULL;
	i = -1;
	while (args[++i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(args[i]), i));
	ft_check(a, args);
	ft_algo(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
