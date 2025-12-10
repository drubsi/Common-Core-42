/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:30:41 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/05 06:47:21 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_greater_b(t_data **stacks, int a, int b, int c)
{
	if (b > c)
	{
		ft_sa(stacks);
		ft_rra(stacks);
	}
	else if (a > c)
		ft_ra(stacks);
	else
		ft_sa(stacks);
}

void	a_less_b(t_data **stacks, int a, int b, int c)
{
	if (a > c)
		ft_rra(stacks);
	else if (b > c)
	{
		ft_sa(stacks);
		ft_ra(stacks);
	}
}

void	sort_3_numbers(t_data **stacks)
{
	int	a;
	int	b;
	int	c;

	if (!(*stacks)->stack_a->content && !(*stacks)->stack_a->next->content
		&& !(*stacks)->stack_a->next->next->content)
		return ;
	a = *(int *)(*stacks)->stack_a->content;
	b = *(int *)(*stacks)->stack_a->next->content;
	c = *(int *)(*stacks)->stack_a->next->next->content;
	if (a > b)
	{
		a_greater_b(stacks, a, b, c);
	}
	else
	{
		a_less_b(stacks, a, b, c);
	}
}
