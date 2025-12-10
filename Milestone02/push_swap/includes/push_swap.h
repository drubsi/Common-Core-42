/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-s <drubio-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:23:01 by drubio-s          #+#    #+#             */
/*   Updated: 2025/04/08 09:14:29 by drubio-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*list;
	int		size_a;
}	t_data;

//Error & release functions
void	ft_error_1(void);
void	ft_del_node(void *content);
void	release_all(t_data **stacks);

//Stack functions
int		init_stacks(t_data *stacks, int argc, const char **argv);

//Checking Functions
void	convert_to_numbers_and_validate_args(int argc, const char **argv);
void	check_int_min_max(int size, long int *number_list);
void	check_no_number(int argc, const char **argv);
void	check_duplicate_number(int size, long int *number_list);
void	check_order_arg(int size, long int *number_list);

//Instructions Functions
void	ft_ra(t_data **stacks);
void	ft_rb(t_data **stacks);
void	ft_rr(t_data **stacks);
void	ft_sa(t_data **stacks);
void	ft_sb(t_data **stacks);
void	ft_ss(t_data **stacks);
void	ft_rra(t_data **stacks);
void	ft_rrb(t_data **stacks);
void	ft_rrr(t_data **stacks);
void	ft_pa(t_data **stacks);
void	ft_pb(t_data **stacks);

//Sort 3 numbers Algorithm
void	a_greater_b(t_data **stacks, int a, int b, int c);
void	a_less_b(t_data **stacks, int a, int b, int c);
void	sort_3_numbers(t_data **stacks);

//Sort 4 & 5 numbers Algorithm
void	get_min_position(t_data **stacks);
void	rotate_and_push(t_data **stacks, int position);
void	sort_4_and_5_numbers(t_data **stacks, int size_stack);

//Chunk sort Algorithm
	//->Chunk split
void	push_chunks(t_data **stacks);
void	push_one_chunk(t_data **stacks,
			int *chunk_min, int *chunk_max, int *chunk_size);
void	rotate_chunk(t_data **stacks, int *chunk_min, int *chunk_max);
int		count_ra_to_chunk(t_list *stack_a, int *chunk_min, int *chunk_max);
int		count_rra_to_chunk(t_list *stack_a, int *chunk_min, int *chunk_max);
	//->Chunk utils rebuild
void	rebuild_stack_a(t_data **stacks);
int		remaining_chunks(t_list *stack_a, int chunk_min, int chunk_max);
int		find_max_b(t_list *stack_b);

//Sort and create indexes
void	ft_copy_list(t_data **stacks);
void	ft_order(t_data **stacks);
void	asign_sorted_index(t_data **stacks);

//Functions Groups
void	check_arg(int argc, long int *number_list);
void	algorithm_selector(t_data **stacks);
void	transform_and_sort_index(t_data **stacks);
void	chunk_sort(t_data **stacks);

#endif
