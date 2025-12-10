/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_5_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:27:48 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/04 19:31:07 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_position(t_data **stacks)
{
	t_list	*stack_aux;
	int		value_min;
	int		position;
	int		i;

	i = 0;
	position = 0;
	stack_aux = (*stacks)->stack_a;
	value_min = *(int *)stack_aux->content;
	while (stack_aux)
	{
		if (value_min > *(int *)stack_aux->content)
		{
			value_min = *(int *)stack_aux->content;
			position = i;
		}
		stack_aux = stack_aux->next;
		i++;
	}
	rotate_and_push(stacks, position);
}

void	rotate_and_push(t_data **stacks, int position)
{
	int	size;

	size = ft_lstsize((*stacks)->stack_a);
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ft_ra(stacks);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			ft_rra(stacks);
			position++;
		}
	}
	ft_pb(stacks);
}

void	sort_4_and_5_numbers(t_data **stacks, int size_stack)
{
	int	size;

	size = ft_lstsize((*stacks)->stack_a);
	if (size_stack == 4)
	{
		get_min_position(stacks);
		sort_3_numbers(stacks);
		ft_pa(stacks);
	}
	if (size_stack == 5)
	{
		while (size > 3)
		{
			get_min_position(stacks);
			size--;
		}
		sort_3_numbers(stacks);
		ft_pa(stacks);
		ft_pa(stacks);
	}
}
