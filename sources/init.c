/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:59:15 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/05 18:14:46 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_empty_string(char *str)
{
	int i;

	i = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

char	**free_tab(char **split)
{
	int i;

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
	t_stack *a;
	t_stack *b;
	// t_stack *tmp;
	// t_stack *tmp2;
	char **args;
	int i;
	
	i = 0;
	a = NULL;
	b = NULL;
	args = ft_split(str, ' ');
	if (!args)
		return;
	if (!args[0])
		exit_error(overflow, a, args);
	while (args[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(args[i]), i));
		i++;
	}
	check_overflow(a, args);
	check_double(a, args);
	is_sorted(a, args);
	free_tab(args);
	// tmp = a;
	// tmp2 = b;
	// printf("STACK A\n\n");
	// while (tmp->next)
	// {
	// 	printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp->value, tmp->pos, tmp->next->value);
	// 	tmp = tmp->next;
	// }
	// printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp->value, tmp->pos, tmp->next);
	// printf("\n\nSTACK B\n\n");
	// if (b == NULL)
	// 	printf("Stack B is empty!\n\n");
	// else
	// {
	// 	while (tmp2->next)
	// 	{
	// 		printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp2->value, tmp2->pos, tmp2->next->value);
	// 		tmp2 = tmp2->next;
	// 	}
	// 	printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp2->value, tmp2->pos, tmp2->next);

	// }
	if(ft_lstsize(a) == 2)
		sort_two(&a);
	else if (ft_lstsize(a) == 3)
		sort_three(&a);
	else if (ft_lstsize(a) == 4)
		sort_four(&a, &b);
	else
		sort_big_list(&a, &b);
	// tmp = a;
	// tmp2 = b;
	// printf("\nAFTER SORT\n");
	// printf("STACK A\n\n");
	// while (tmp->next)
	// {
	// 	printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp->value, tmp->pos, tmp->next->value);
	// 	tmp = tmp->next;
	// }
	// printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp->value, tmp->pos, tmp->next);
	// printf("\n\nSTACK B\n\n");
	// if (b == NULL)
	// 	printf("Stack B is empty!\n\n");
	// else
	// {
	// 	while (tmp2->next)
	// 	{
	// 		printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp2->value, tmp2->pos, tmp2->next->value);
	// 		tmp2 = tmp2->next;
	// 	}
	// 	printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp2->value, tmp2->pos, tmp2->next);
	// }
	ft_lstclear(&a);
	ft_lstclear(&b);
}

void	init_multi_arg(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	// t_stack *tmp;
	// t_stack *tmp2;
	char **args;
	int i;
	int j;
	
	i = 1;
	j = 0;
	a = NULL;
	b = NULL;
	args = malloc(sizeof(char *) * (argc));
	if(!args)
		return;
	while(argv[i])
		args[j++] = ft_strdup(argv[i++]);
	args[j] = NULL;
	i = 0;
	while (args[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(args[i]), i));
		i++;
	}
	check_overflow(a, args);
	check_double(a, args);
	is_sorted(a, args);
	free_tab(args);
	// tmp = a;
	// tmp2 = b;
	// printf("STACK A\n\n");
	// while (tmp->next)
	// {
	// 	printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp->value, tmp->pos, tmp->next->value);
	// 	tmp = tmp->next;
	// }
	// printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp->value, tmp->pos, tmp->next);
	// printf("\n\nSTACK B\n\n");
	// if (b == NULL)
	// 	printf("Stack B is empty!\n");
	// else
	// {
	// 	while (tmp2->next)
	// 	{
	// 		printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp2->value, tmp2->pos, tmp2->next->value);
	// 		tmp2 = tmp2->next;
	// 	}
	// 	printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp2->value, tmp2->pos, tmp2->next);

	// }
	if(ft_lstsize(a) == 2)
		sort_two(&a);
	else if (ft_lstsize(a) == 3)
		sort_three(&a);
	else if (ft_lstsize(a) == 4)
		sort_four(&a, &b);
	else
		sort_big_list(&a, &b);
	// tmp = a;
	// tmp2 = b;
	// printf("\nAFTER SORT\n");
	// printf("STACK A\n\n");
	// while (tmp->next)
	// {
	// 	printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp->value, tmp->pos, tmp->next->value);
	// 	tmp = tmp->next;
	// }
	// printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp->value, tmp->pos, tmp->next);
	// printf("\n\nSTACK B\n\n");
	// if (b == NULL)
	// 	printf("Stack B is empty!\n\n");
	// else
	// {
	// while (tmp2->next)
	// {
	// 	printf("value : [%d] || pos : [%d] || next value: [%d]\n", tmp2->value, tmp2->pos, tmp2->next->value);
	// 	tmp2 = tmp2->next;
	// }
	// printf ("value : [%d] || pos : [%d] || next value: [%p]\n", tmp2->value, tmp2->pos, tmp2->next);
	// }
	ft_lstclear(&a);
	ft_lstclear(&b);
}