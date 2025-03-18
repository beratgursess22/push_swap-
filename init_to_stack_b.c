/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:52:54 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:52:57 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*fake_a;
	t_list	*target_node;
	long	match_number;

	while (stack_b)
	{
		match_number = LONG_MAX;
		fake_a = stack_a;
		while (fake_a)
		{
			if ((fake_a->number > stack_b->number)
				&& (fake_a->number < match_number))
			{
				match_number = fake_a->number;
				target_node = fake_a;
			}
			fake_a = fake_a->next;
		}
		if (match_number == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_stack_b(t_list *stack_a, t_list *stack_b)
{
	find_to_index(stack_a);
	find_to_index(stack_b);
	find_target_b(stack_a, stack_b);
}
