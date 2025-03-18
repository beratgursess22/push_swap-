/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:54:05 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:54:07 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_both(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b, false);
	find_to_index(*stack_a);
	find_to_index(*stack_b);
}

void	move_stack_a_to_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapes_node(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	top_for_push(stack_a, cheapest_node, 'a');
	top_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a, false);
}

void	move_stack_b_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	top_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, false);
}

void	min_on_top(t_list **stack_a)
{
	while ((*stack_a)->number != find_min(*stack_a)->number)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len_stack_b;

	len_stack_b = ft_lstsize(*stack_a);
	if (len_stack_b-- > 3 && !(is_sorted(stack_a)))
		pb(stack_b, stack_a, false);
	if (len_stack_b-- > 3 && !(is_sorted(stack_a)))
		pb(stack_b, stack_a, false);
	while (len_stack_b-- > 3 && !(is_sorted(stack_a)))
	{
		init_stack_a(*stack_a, *stack_b);
		move_stack_a_to_stack_b(stack_a, stack_b);
	}
	sorted_three(stack_a);
	while (*stack_b)
	{
		init_stack_b(*stack_a, *stack_b);
		move_stack_b_to_stack_a(stack_a, stack_b);
	}
	find_to_index(*stack_a);
	min_on_top(stack_a);
}
