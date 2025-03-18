/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:52:34 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:52:36 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->number = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	ft_error(t_list *stack_a, char **string)
{
	free_stack(&stack_a);
	free_for_string(string);
	write(2, "Error\n", 6);
	exit(0);
}

void	free_for_string(char **string)
{
	int	i;

	i = 0;
	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	free(string);
}
