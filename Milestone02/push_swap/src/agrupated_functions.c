/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agrupated_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:11:27 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 09:03:23 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int size, long int *number_list)
{
	check_int_min_max(size, number_list);
	check_duplicate_number(size, number_list);
	check_order_arg(size, number_list);
}

void	transform_and_sort_index(t_data **stacks)
{
	ft_copy_list(stacks);
	ft_order(stacks);
	asign_sorted_index(stacks);
}

void	algorithm_selector(t_data **stacks)
{
	int	size_stack_a;

	size_stack_a = ft_lstsize((*stacks)->stack_a);
	if (size_stack_a == 2)
		ft_sa (stacks);
	else if (size_stack_a == 3)
		sort_3_numbers (stacks);
	else if (size_stack_a == 4 || size_stack_a == 5)
		sort_4_and_5_numbers (stacks, size_stack_a);
	else
		chunk_sort (stacks);
}

void	chunk_sort(t_data **stacks)
{
	push_chunks(stacks);
	rebuild_stack_a(stacks);
}
