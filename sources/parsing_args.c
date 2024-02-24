/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:47:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/13 20:12:03 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_overflow(t_stack *a, char **args)
{
	t_stack *tmp;
	int i;
	int j;
	char *nb;
	
	tmp = a;
	i = 0;
	while (tmp)
	{
		j = 0;
		nb = ft_itoa(tmp->value);
		while (args[i][j] == '0' || args[i][j] == '+')
			j++;
		if (args[i][j] != '\0' && ft_strcmp(args[i] + j, nb) != 0)
		{
			free(nb);
			exit_error(overflow, "Something went wrong...", a, args);
		}
		free(nb);
		i++;
		tmp = tmp->next;
	}
}

void	check_double(t_stack *a, char **args)
{
	t_stack *tmp;
	t_stack *tmp2;
	tmp = a;
	int value_test;

	while(tmp)
	{
		tmp2 = tmp->next;
		value_test = tmp->value;
		while(tmp2)
		{
			if (tmp2->value == value_test)
				exit_error(double_nb, "Doubles detected ! MF", a, args);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static int	check_digit(char *str)
{
	int i;
	i = 0;
	
	while(str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

void	pars_one_arg(char *str)
{
	if (!check_empty_string(str))
		exit_error(arg_empty, "Empty string!", NULL, NULL);
	if (!check_digit(str))
		exit_error(wrong_input, "Argument(s) need(s) ONLY digits and accept ONLY ONE + or - sign!", NULL, NULL);
}

int	check_env(char **envp)
{
	const char *env;
	char *val_va;
	int i;

	env = "USER";
	val_va = NULL;
	i = 0;
	
	while (envp[i] != NULL)
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}
