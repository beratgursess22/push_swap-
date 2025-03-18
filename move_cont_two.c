/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cont_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:53 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:53:55 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_list **stack_a, bool write)
{
	rev_rotate(stack_a);
	if (!write)
		ft_printf("rra\n");
}

void	rrb(t_list **stack_b, bool write)
{
	rev_rotate(stack_b);
	if (!write)
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b, bool write)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!write)
		ft_printf("rrr\n");
}
