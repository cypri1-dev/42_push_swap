/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:34:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/03/09 18:20:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main (int argc, char **argv, char **envp)
{
	int i;

	i = 1;
	if(!check_env(envp))
		exit_error(env_error, NULL, NULL);
	if(argc < 2)
		exit_error(arg_missing, NULL, NULL);
	if (argc == 2)
	{
		pars_one_arg(argv[1]);
		init_arg(argv[1]);
	}
	if (argc > 2)
	{
		while(argv[i])
			pars_one_arg(argv[i++]);
		init_multi_arg(argc, argv);
	}
	return (0);
}