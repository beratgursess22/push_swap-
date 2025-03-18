/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:03 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:53:05 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_list **stack_a, int number)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack_a)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->number = number;
	node->cheapest_node = 0;
	if (!(*stack_a))
	{
		*stack_a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack_a);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	ft_lstsize(t_list *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_list	*find_max(t_list *stack)
{
	t_list	*max_node;
	long	max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_list	*find_min(t_list *stack)
{
	long	min;
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
