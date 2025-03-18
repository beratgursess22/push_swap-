/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:09 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:53:12 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_list **stack_a, bool write)
{
	rotate(stack_a);
	if (!write)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, bool write)
{
	rotate(stack_b);
	if (!write)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b, bool write)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!write)
		ft_printf("rr\n");
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	find_to_index(*stack_a);
	find_to_index(*stack_b);
}
