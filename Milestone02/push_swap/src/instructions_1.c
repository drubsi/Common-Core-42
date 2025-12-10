/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:29:23 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/07 12:21:38 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_data **stacks)
{
	t_list	*temp_node;

	if (!(*stacks)->stack_a || !(*stacks)->stack_a->next)
		return ;
	if ((*stacks)->stack_a)
	{
		temp_node = (*stacks)->stack_a;
		(*stacks)->stack_a = (*stacks)->stack_a->next;
		temp_node->next = NULL;
		ft_lstadd_back(&(*stacks)->stack_a, temp_node);
		ft_printf("ra\n");
	}
}

void	ft_rb(t_data **stacks)
{
	t_list	*temp_node;

	if (!(*stacks)->stack_b || !(*stacks)->stack_b->next)
		return ;
	if ((*stacks)->stack_b)
	{
		temp_node = (*stacks)->stack_b;
		(*stacks)->stack_b = (*stacks)->stack_b->next;
		temp_node->next = NULL;
		ft_lstadd_back(&(*stacks)->stack_b, temp_node);
		ft_printf("rb\n");
	}
}

void	ft_rra(t_data **stacks)
{
	t_list	*temp_node;
	t_list	*temp_node_2;

	if (!(*stacks)->stack_a || !(*stacks)->stack_a->next)
		return ;
	if ((*stacks)->stack_a)
	{
		temp_node = (*stacks)->stack_a;
		while (temp_node->next->next)
			temp_node = temp_node->next;
		temp_node_2 = temp_node->next;
		temp_node->next = NULL;
		temp_node_2->next = (*stacks)->stack_a;
		(*stacks)->stack_a = temp_node_2;
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_data **stacks)
{
	t_list	*temp_node;
	t_list	*temp_node_2;

	if (!(*stacks)->stack_b || !(*stacks)->stack_b->next)
		return ;
	if ((*stacks)->stack_b)
	{
		temp_node = (*stacks)->stack_b;
		while (temp_node->next->next)
			temp_node = temp_node->next;
		temp_node_2 = temp_node->next;
		temp_node->next = NULL;
		temp_node_2->next = (*stacks)->stack_b;
		(*stacks)->stack_b = temp_node_2;
		ft_printf("rrb\n");
	}
}
