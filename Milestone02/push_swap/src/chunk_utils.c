/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:07:31 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 09:08:45 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rebuild_stack_a(t_data **stacks)
{
	int	size;
	int	position;

	while ((*stacks)->stack_b)
	{
		size = ft_lstsize((*stacks)->stack_b);
		position = find_max_b((*stacks)->stack_b);
		if (position <= size / 2)
			while (position-- > 0)
				ft_rb(stacks);
		else
			while (position++ < size)
				ft_rrb(stacks);
		ft_pa(stacks);
	}
}

int	remaining_chunks(t_list *stack_a, int chunk_min, int chunk_max)
{
	t_list	*stack_aux;

	stack_aux = stack_a;
	while (stack_aux)
	{
		if (*(int *)stack_aux->content >= chunk_min
			&& *(int *)stack_aux->content <= chunk_max)
			return (1);
		stack_aux = stack_aux->next;
	}
	return (0);
}

int	find_max_b(t_list *stack_b)
{
	t_list	*stack_aux;
	int		max;
	int		index;
	int		position;

	stack_aux = stack_b;
	max = *(int *)stack_aux->content;
	index = 0;
	position = 0;
	while (stack_aux)
	{
		if (*(int *)stack_aux->content > max)
		{
			max = *(int *)stack_aux->content;
			position = index;
		}
		stack_aux = stack_aux->next;
		index++;
	}
	return (position);
}
