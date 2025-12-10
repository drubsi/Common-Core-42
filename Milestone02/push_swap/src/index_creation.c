/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:17:01 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/05 06:46:23 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copy_list(t_data **stacks)
{
	t_list	*stack_aux;
	int		i;

	i = 0;
	stack_aux = (*stacks)->stack_a;
	(*stacks)->size_a = ft_lstsize(stack_aux);
	(*stacks)->list = (int *)malloc((*stacks)->size_a * sizeof(int));
	while (stack_aux)
	{
		(*stacks)->list[i] = *(int *)stack_aux->content;
		stack_aux = stack_aux->next;
		i++;
	}
}

void	ft_order(t_data **stacks)
{
	int	i;
	int	swap;
	int	temp;

	swap = 1;
	while (swap)
	{
		i = 0;
		swap = 0;
		while (i < (*stacks)->size_a - 1)
		{
			if ((*stacks)->list[i] > (*stacks)->list[i + 1])
			{
				temp = (*stacks)->list[i];
				(*stacks)->list[i] = (*stacks)->list[i + 1];
				(*stacks)->list[i + 1] = temp;
				swap = 1;
			}
			i++;
		}
	}
}

void	asign_sorted_index(t_data **stacks)
{
	t_list	*stack_aux;
	int		i;
	int		original;
	int		flag;

	stack_aux = (*stacks)->stack_a;
	while (stack_aux)
	{
		original = *(int *)stack_aux->content;
		i = 0;
		flag = 0;
		while (i < (*stacks)->size_a && !flag)
		{
			if ((*stacks)->list[i] == original)
			{
				*(int *)stack_aux->content = i;
				flag = 1;
			}
			i++;
		}
		stack_aux = stack_aux->next;
	}
}
