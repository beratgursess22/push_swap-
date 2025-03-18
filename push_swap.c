/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:22 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:53:24 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	create_stack_a(argv, argc, &stack_a);
	if (!(is_sorted(&stack_a)))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a, false);
		else if (ft_lstsize(stack_a) == 3)
			sorted_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}
