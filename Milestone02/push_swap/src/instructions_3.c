/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:35:37 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/07 12:22:01 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_data **stacks)
{
	t_list	*temp_node_a;
	t_list	*temp_node_b;

	if (!(*stacks)->stack_a || !(*stacks)->stack_a->next
		|| !(*stacks)->stack_b || !(*stacks)->stack_b->next)
		return ;
	if ((*stacks)->stack_a && (*stacks)->stack_b)
	{
		temp_node_a = (*stacks)->stack_a;
		(*stacks)->stack_a = (*stacks)->stack_a->next;
		temp_node_a->next = NULL;
		ft_lstadd_back(&(*stacks)->stack_a, temp_node_a);
		temp_node_b = (*stacks)->stack_b;
		(*stacks)->stack_b = (*stacks)->stack_b->next;
		temp_node_b->next = NULL;
		ft_lstadd_back(&(*stacks)->stack_b, temp_node_b);
		ft_printf ("rr\n");
	}
}

void	ft_rrr(t_data **stacks)
{
	t_list	*temp_node;
	t_list	*temp_node_2;

	if (!(*stacks)->stack_a || !(*stacks)->stack_a->next
		|| !(*stacks)->stack_b || !(*stacks)->stack_b->next)
		return ;
	if ((*stacks)->stack_a && (*stacks)->stack_b)
	{
		temp_node = (*stacks)->stack_a;
		while (temp_node->next->next)
			temp_node = temp_node->next;
		temp_node_2 = temp_node->next;
		temp_node->next = NULL;
		temp_node_2->next = (*stacks)->stack_a;
		(*stacks)->stack_a = temp_node_2;
		temp_node = (*stacks)->stack_b;
		while (temp_node->next->next)
			temp_node = temp_node->next;
		temp_node_2 = temp_node->next;
		temp_node->next = NULL;
		temp_node_2->next = (*stacks)->stack_b;
		(*stacks)->stack_b = temp_node_2;
		ft_printf ("rrr\n");
	}
}

void	ft_ss(t_data **stacks)
{
	t_list	*temp_node;
	t_list	*temp_node_2;
	t_list	*temp_node_3;
	t_list	*temp_node_4;

	if (!(*stacks)->stack_a || !(*stacks)->stack_a->next
		|| !(*stacks)->stack_b || !(*stacks)->stack_b->next)
		return ;
	if ((*stacks)->stack_a && (*stacks)->stack_b)
	{
		temp_node = (*stacks)->stack_a;
		temp_node_2 = (*stacks)->stack_a->next;
		(*stacks)->stack_a = temp_node_2;
		temp_node->next = temp_node_2->next;
		temp_node_2->next = temp_node;
		temp_node_3 = (*stacks)->stack_b;
		temp_node_4 = (*stacks)->stack_b->next;
		(*stacks)->stack_b = temp_node_4;
		temp_node_3->next = temp_node_4->next;
		temp_node_4->next = temp_node_3;
		ft_printf ("ss\n");
	}
}
