/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:26:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/10 14:47:48 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

int	print_int(int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nb);
	len = print_string(num);
	free(num);
	return (len);
}

/*int main(void)
{
	int nb = -85;
	printf("%d\n", print_int(nb));
	return(0);
}*/