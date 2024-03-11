/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:38:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/11 07:50:21 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

/*all defines*/

# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"
# define ENDC "\033[0m"

/*all enums*/

enum	e_state
{
	env_error = 1,
	arg_missing = 2,
	wrong_input = 3,
	arg_empty = 4,
	double_nb = 5,
	overflow = 6,
	sorted = 7,
};

/*all structures*/

#endif