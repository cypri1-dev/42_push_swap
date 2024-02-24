/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:38:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/19 15:40:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS
# define PUSH_SWAP_UTILS

/*all defines*/

# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"
# define ENDC "\033[0m"

/*all enums*/

enum	e_state
{
	env_error = 2,
	arg_missing = 2,
	wrong_input = 2,
	arg_empty = 2,
	double_nb = 5,
	overflow = 5,
	sorted = 3,
};

/*all structures*/

#endif