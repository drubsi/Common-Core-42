/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:52 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 09:03:55 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_data	*stacks;

	convert_to_numbers_and_validate_args(argc, argv);
	stacks = (t_data *)malloc(sizeof(t_data));
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	init_stacks (stacks, argc, argv);
	transform_and_sort_index(&stacks);
	algorithm_selector(&stacks);
	release_all(&stacks);
	return (0);
}
