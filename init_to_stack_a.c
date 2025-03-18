/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:52:42 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:52:43 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_to_index(t_list *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		index++;
	}
}

void	find_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*fake_b;
	t_list	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		fake_b = stack_b;
		while (fake_b)
		{
			if (fake_b->number < stack_a->number
				&& fake_b->number > best_match_index)
			{
				best_match_index = fake_b->number;
				target_node = fake_b;
			}
			fake_b = fake_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	calculate_cost(t_list *stack_a, t_list *stack_b)
{
	int	stack_len_a;
	int	stack_len_b;

	stack_len_a = ft_lstsize(stack_a);
	stack_len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = stack_len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += stack_len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	find_min_cost(t_list *stack_a)
{
	long	min_value;
	t_list	*cheapest_node;

	if (!stack_a)
		return ;
	min_value = LONG_MAX;
	while (stack_a)
	{
		if (stack_a->push_cost < min_value)
		{
			min_value = stack_a->push_cost;
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	cheapest_node->cheapest_node = true;
}

void	init_stack_a(t_list *stack_a, t_list *stack_b)
{
	find_to_index(stack_a);
	find_to_index(stack_b);
	find_target_a(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	find_min_cost(stack_a);
}
