/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:33:34 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/07 12:27:54 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data **stacks)
{
	t_list	*temp_node;
	t_list	*temp_node_2;

	if (!(*stacks)->stack_a || !(*stacks)->stack_a->next)
		return ;
	if ((*stacks)->stack_a)
	{
		temp_node = (*stacks)->stack_a;
		temp_node_2 = (*stacks)->stack_a->next;
		(*stacks)->stack_a = temp_node_2;
		temp_node->next = temp_node_2->next;
		temp_node_2->next = temp_node;
		ft_printf("sa\n");
	}
}

void	ft_sb(t_data **stacks)
{
	t_list	*temp_node;
	t_list	*temp_node_2;

	if (!(*stacks)->stack_b || !(*stacks)->stack_b->next)
		return ;
	if ((*stacks)->stack_b)
	{
		temp_node = (*stacks)->stack_b;
		temp_node_2 = (*stacks)->stack_b->next;
		(*stacks)->stack_b = temp_node_2;
		temp_node->next = temp_node_2->next;
		temp_node_2->next = temp_node;
		ft_printf("sb\n");
	}
}

void	ft_pb(t_data **stacks)
{
	t_list	*temp_node;

	if (!(*stacks)->stack_a)
		return ;
	else
	{
		temp_node = (*stacks)->stack_a;
		(*stacks)->stack_a = (*stacks)->stack_a->next;
		temp_node->next = NULL;
		ft_lstadd_front(&(*stacks)->stack_b, temp_node);
		ft_printf ("pb\n");
	}
}

void	ft_pa(t_data **stacks)
{
	t_list	*temp_node;

	if (!(*stacks)->stack_b)
		return ;
	else
	{
		temp_node = (*stacks)->stack_b;
		(*stacks)->stack_b = (*stacks)->stack_b->next;
		temp_node->next = NULL;
		ft_lstadd_front(&(*stacks)->stack_a, temp_node);
		ft_printf ("pa\n");
	}
}
