/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:37:38 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/05 15:24:08 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUSH_SWAP
# define LIBFT_PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

/*all structs*/

typedef struct s_stack
{
	int	value;
	int pos;
	int cost;
	struct s_stack *target;
	struct s_stack *previous;
	struct s_stack *next;
}				t_stack;

typedef	struct s_extremum
{
	struct s_stack *min;
	struct s_stack *max;
	int pos;
}			t_extremum;

/*strings prototype functions*/

int	ft_strlen(char *str);
char	*ft_strstr(char *haystack, char *needle);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int nbr);
void	*ft_calloc(size_t nmeb, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
int	ft_atoi(char *str);
int ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

/*printf prototyope functions*/

int	ft_printf(const char *input, ...);
int	print_char(char c);
int	print_hexa(unsigned int nb, const char form);
int	print_int(int nb);
int	print_percent(void);
int	print_pointer(unsigned long long ptr);
int	print_string(char *str);
int	print_unsigned(unsigned int nb);

/*all prototype list functions*/

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value, int i);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int	ft_lstsize(t_stack *lst);

#endif