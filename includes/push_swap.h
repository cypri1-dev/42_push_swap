/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:34:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 10:33:08 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*all includes*/

# include "../libft_push_swap/libft_push_swap.h"
# include "push_swap_utils.h"
# include <stdio.h>

/*strings functions prototypes*/

char		*ft_strchr(const char *s, int c);

/*push_swap parsing - exit functions prototypes*/

int			check_env(char **envp);
void		ft_check(t_stack *a, char **args);
void		ft_algo(t_stack **a, t_stack **b);
void		exit_error(enum e_state i, t_stack *a, char **args);
void		pars_one_arg(char *str);
void		init_multi_arg(int argc, char **argv);
void		init_arg(char *str);
char		**free_tab(char **split);
void		check_double(t_stack *a, char **args);
void		check_overflow(t_stack *a, char **args);
int			check_empty_string(char *str);
void		update_pos(t_stack *stack);

/*push_swap instructions*/

void		swap_a(t_stack **a, int print);
void		swap_b(t_stack **b, int print);
void		swap_a_b(t_stack **a, t_stack **b);
void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);
void		rotate_a(t_stack **a, int print);
void		rotate_b(t_stack **b, int print);
void		rotate_a_b(t_stack **a, t_stack **b);
void		reverse_rotate_a(t_stack **a, int print);
void		reverse_rotate_b(t_stack **b, int print);
void		reverse_rotate_a_b(t_stack **a, t_stack **b);

/*push_swap algo functions*/

void		is_sorted(t_stack *a, char **args);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_worst_case(t_stack **a, t_stack **b);
void		sort_stacks(t_stack **a, t_stack **b);
void		sort_big_list(t_stack **a, t_stack **b);
t_extremum	is_new_extremum(t_stack **a, t_extremum extrm);
t_stack		*calculate_cost(t_stack **a, t_stack **b);
int			is_up_or_down(t_stack **lst, t_stack *node);
t_stack		*find_target(t_stack *node, t_stack **b);
void		move_to_pos(t_stack **a, t_stack **b, t_stack *node);
void		final_sort(t_stack **a, t_stack **b);
void		calculate_size(t_stack **a, t_stack **b, t_cost *nbr);
void		save_best_target(t_cost *nbr, t_stack **best_node, t_stack *tmp,
				t_stack *target);

#endif