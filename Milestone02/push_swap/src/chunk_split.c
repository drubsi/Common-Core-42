/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:22:22 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 09:13:17 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_data **stacks)
{
	int	chunk_min;
	int	chunk_max;
	int	chunk_size;

	(*stacks)->size_a = ft_lstsize((*stacks)->stack_a);
	if ((*stacks)->size_a < 5)
		chunk_size = 1;
	else if ((*stacks)->size_a <= 100)
		chunk_size = (*stacks)->size_a / 5;
	else
		chunk_size = (*stacks)->size_a / 9;
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while ((*stacks)->stack_a)
	{
		push_one_chunk(stacks, &chunk_min, &chunk_max, &chunk_size);
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
}

void	push_one_chunk(t_data **stacks,
	int *chunk_min, int *chunk_max, int *chunk_size)
{
	int	node_head;

	while (remaining_chunks((*stacks)->stack_a, *chunk_min, *chunk_max))
	{
		rotate_chunk(stacks, chunk_min, chunk_max);
		node_head = *(int *)(*stacks)->stack_a->content;
		if (node_head < *chunk_min + (*chunk_size / 2))
			ft_pb(stacks);
		else if (node_head >= *chunk_max * 4 / 5)
		{
			ft_pb(stacks);
			ft_rb(stacks);
		}
		else
			ft_pb(stacks);
	}
}

void	rotate_chunk(t_data **stacks, int *chunk_min, int *chunk_max)
{
	int	first_position;
	int	last_position;

	first_position = count_ra_to_chunk((*stacks)->stack_a,
			chunk_min, chunk_max);
	last_position = count_rra_to_chunk((*stacks)->stack_a,
			chunk_min, chunk_max);
	if (first_position == -1 && last_position == -1)
		return ;
	else if (last_position == -1 || first_position <= last_position)
		while (first_position-- > 0)
			ft_ra(stacks);
	else
		while (last_position-- > 0)
			ft_rra(stacks);
}

int	count_ra_to_chunk(t_list *stack_a, int *chunk_min, int *chunk_max)
{
	t_list	*stack_aux;
	int		position;

	position = 0;
	stack_aux = stack_a;
	while (stack_aux)
	{
		if (*(int *)stack_aux->content >= *chunk_min
			&& *(int *)stack_aux->content <= *chunk_max)
			return (position);
		position++;
		stack_aux = stack_aux->next;
	}
	return (-1);
}

int	count_rra_to_chunk(t_list *stack_a, int *chunk_min, int *chunk_max)
{
	t_list	*stack_aux;
	int		index;
	int		position;
	int		size;

	size = ft_lstsize(stack_a);
	stack_aux = stack_a;
	index = 0;
	position = -1;
	while (stack_aux)
	{
		if (*(int *)stack_aux->content >= *chunk_min
			&& *(int *)stack_aux->content <= *chunk_max)
			position = index;
		index++;
		stack_aux = stack_aux->next;
	}
	if (position == -1)
		return (-1);
	else
		return (size - position);
}
