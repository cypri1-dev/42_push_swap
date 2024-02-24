/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:15:40 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/10 14:32:34 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
		{
			return ((char *)0);
		}
		i++;
	}
	return ((char *)&s[i]);
}

// int main (void)
// {
// 	char *str = "USER mes amis!";
// 	char c = 'R';

// 	printf ("%s", ft_strchr((const char *)str, (int)c));
// 	return (0);
// }