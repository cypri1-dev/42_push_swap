/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:18:52 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 20:49:02 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*all structs*/

enum				e_state
{
	env_error = 1,
	arg_missing = 2,
	wrong_input = 3,
	arg_empty = 4,
	double_nb = 5,
	overflow = 6,
	sorted = 7,
};

typedef struct s_cost
{
	int				target_cost;
	int				best_cost;
	int				len_a;
	int				len_b;
}					t_cost;

typedef struct s_diff
{
	int				diff;
	int				best_diff;
}					t_diff;

typedef struct s_stack
{
	int				value;
	int				pos;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_extremum
{
	struct s_stack	*min;
	struct s_stack	*max;
	int				pos;
}					t_extremum;

/*strings prototype functions*/

int					ft_strlen(char *str);
char				*ft_strstr(char *haystack, char *needle);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_itoa(int nbr);
void				*ft_calloc(size_t nmeb, size_t size);
void				ft_bzero(void *s, size_t n);
char				**ft_split(char const *s, char c);
int					ft_atoi(char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);

/*printf prototyope functions*/

int					ft_printf(const char *input, ...);
int					print_char(char c);
int					print_hexa(unsigned int nb, const char form);
int					print_int(int nb);
int					print_percent(void);
int					print_pointer(unsigned long long ptr);
int					print_string(char *str);
int					print_unsigned(unsigned int nb);

/*all prototype list functions*/

void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int value, int i);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstdelone(t_stack *lst);
void				ft_lstclear(t_stack **lst);
int					ft_lstsize(t_stack *lst);

/*gnl prototype functions*/

char				*gnl_strchr(char *s, int c);
size_t				gnl_strlen(const char *str);
void				*gnl_memcpy(void *dest, const void *src, size_t n);
char				*gnl_strjoin(char const *s1, char const *s2);
void				*gnl_calloc(size_t nmeb, size_t size);
char				*ft_strdup_gnl(const char *s);
char				*extract_line(char *buffer);
char				*obtain_rest(char *buffer);
char				*get_next_line(int fd);

/*push_swap parsing - exit functions prototypes*/

int					check_env(char **envp);
void				ft_check(t_stack *a, char **args);
void				ft_algo(t_stack **a, t_stack **b);
void				exit_error(enum e_state i, t_stack *a, char **args);
void				pars_one_arg(char *str);
void				init_multi_arg(int argc, char **argv);
void				init_arg(char *str);
char				**free_tab(char **split);
void				check_double(t_stack *a, char **args);
void				check_overflow(t_stack *a, char **args);
int					check_empty_string(char *str);
void				update_pos(t_stack *stack);

/*push_swap instructions*/

void				swap_a(t_stack **a, int print);
void				swap_b(t_stack **b, int print);
void				swap_a_b(t_stack **a, t_stack **b, int print);
void				push_a(t_stack **a, t_stack **b, int print);
void				push_b(t_stack **a, t_stack **b, int print);
void				rotate_a(t_stack **a, int print);
void				rotate_b(t_stack **b, int print);
void				rotate_a_b(t_stack **a, t_stack **b, int print);
void				reverse_rotate_a(t_stack **a, int print);
void				reverse_rotate_b(t_stack **b, int print);
void				reverse_rotate_a_b(t_stack **a, t_stack **b, int print);

/*push_swap algo functions*/

void				is_sorted(t_stack *a, char **args);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_worst_case(t_stack **a, t_stack **b);
void				sort_stacks(t_stack **a, t_stack **b);
void				sort_big_list(t_stack **a, t_stack **b);
t_extremum			is_new_extremum(t_stack **a, t_extremum extrm);
t_stack				*calculate_cost(t_stack **a, t_stack **b);
int					is_up_or_down(t_stack **lst, t_stack *node);
t_stack				*find_target(t_stack *node, t_stack **b);
void				move_to_pos(t_stack **a, t_stack **b, t_stack *node);
void				final_sort(t_stack **a, t_stack **b);
void				calculate_size(t_stack **a, t_stack **b, t_cost *nbr);
void				save_best_target(t_cost *nbr, t_stack **best_node,
						t_stack *tmp, t_stack *target);
char				*check_exec(t_stacks *stacks, char *line);
void				first_check(char **envp, int argc);
void				return_checker(char *line, t_stacks stacks);
void				check_part_2(t_stacks *stacks, char *line);
int					check_is_sorted(t_stack *a);

#endif