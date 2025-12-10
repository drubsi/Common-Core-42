/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:07:52 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/05 06:42:20 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_data *stacks, int argc, const char **argv)
{
	t_list		*new_node;
	long int	*str_n;
	int			n;

	n = 1;
	while (n < argc)
	{
		str_n = (long int *)malloc(sizeof (long int));
		if (!str_n)
			ft_error_1 ();
		*str_n = ft_atol(argv[n]);
		new_node = ft_lstnew(str_n);
		if (!new_node)
		{
			free (new_node);
			return (-1);
		}
		ft_lstadd_back(&stacks->stack_a, new_node);
		n++;
	}
	return (0);
}
