/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:54:17 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:54:19 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(char **argv, int argc, t_list **stack_a)
{
	char	**string;
	int		i;
	int		number;
	int		size;

	i = 0;
	string = split_numbers(argc, argv, &size);
	if (!string || string[0] == NULL)
		ft_error(*stack_a, string);
	while (i < size)
	{
		if (check_character(string[i]) == 1)
			ft_error(*stack_a, string);
		number = ft_atoi(string[i], string, stack_a);
		if (!(number >= INT_MIN && number <= INT_MAX))
			ft_error(*stack_a, string);
		append_node(stack_a, (int)number);
		i++;
	}
	if (check_same_character(*stack_a) == 1)
		ft_error(*stack_a, string);
	free_for_string(string);
}

t_list	*find_last(t_list *stack)
{
	t_list	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
