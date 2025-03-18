/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:54:11 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:54:13 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_three(t_list **stack_a)
{
	t_list	*biggest_node;

	biggest_node = find_max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, false);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a, false);
}
