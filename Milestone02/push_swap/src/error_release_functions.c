/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_release_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:57:36 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/06 11:30:26 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_1(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	ft_del_node(void *content)
{
	free(content);
}

void	release_all(t_data **stacks)
{
	ft_lstclear (&(*stacks)->stack_a, ft_del_node);
	ft_lstclear (&(*stacks)->stack_b, ft_del_node);
	free ((*stacks)->list);
	free (*stacks);
}
