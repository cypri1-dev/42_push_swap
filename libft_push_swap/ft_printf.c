/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:26:34 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 07:54:37 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

static int	ft_type(const char *input, va_list args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char(va_arg(args, int));
	else if (*input == 's')
		i += print_string(va_arg(args, char *));
	else if (*input == 'p')
		i += print_pointer(va_arg(args, unsigned long long));
	else if (*input == 'd' || *input == 'i')
		i += print_int(va_arg(args, int));
	else if (*input == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x' || *input == 'X')
		i += print_hexa(va_arg(args, unsigned int), *input);
	else if (*input == '%')
		i += print_percent();
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(args, input);
	if (input == NULL)
		return (-1);
	while (input[i])
	{
		if (input[i] == '%')
		{
			total_len += ft_type(&input[i + 1], args);
			i++;
		}
		else
			total_len += print_char(input[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}
