/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:17 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:53:18 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_list **stack_a, bool write)
{
	swap(stack_a);
	if (!write)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, bool write)
{
	swap(stack_b);
	if (!write)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b, bool write)
{
	swap(stack_a);
	swap(stack_b);
	if (!write)
		ft_printf("ss\n");
}
