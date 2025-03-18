/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:53:29 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 16:08:05 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest_node;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				create_stack_a(char **argv, int argc, t_list **stack_a);
int					check_character(char *str);
int					check_same_character(t_list *node);
void				top_for_push(t_list **stack, t_list *top_node,
						char stack_name);
t_list				*get_cheapes_node(t_list *stack);
int					is_sorted(t_list **stack);
char				**split_numbers(int argc, char **argv, int *size);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					ft_atoi(const char *str, char **string, t_list **stack);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				append_node(t_list **stack_a, int number);
int					ft_lstsize(t_list *lst);
t_list				*find_max(t_list *stack);
t_list				*find_min(t_list *stack);
void				find_min_cost(t_list *stack_a);
t_list				*find_last(t_list *stack);
void				find_target_b(t_list *stack_a, t_list *stack_b);
void				init_stack_b(t_list *stack_a, t_list *stack_b);
void				find_to_index(t_list *stack);
void				find_target_a(t_list *stack_a, t_list *stack_b);
void				calculate_cost(t_list *stack_a, t_list *stack_b);
void				init_stack_a(t_list *stack_a, t_list *stack_b);
void				sort_stack(t_list **stack_a, t_list **stack_b);
void				min_on_top(t_list **stack_a);
void				move_stack_b_to_stack_a(t_list **stack_a, t_list **stack_b);
void				move_stack_a_to_stack_b(t_list **stack_a, t_list **stack_b);
void				rev_rotate_both(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);
void				sorted_three(t_list **stack_a);
void				swap(t_list **head);
void				sa(t_list **stack_a, bool write);
void				sb(t_list **stack_b, bool write);
void				ss(t_list **stack_a, t_list **stack_b, bool write);
void				rotate(t_list **stack);
void				ra(t_list **stack_a, bool write);
void				rb(t_list **stack_b, bool write);
void				rr(t_list **stack_a, t_list **stack_b, bool write);
void				rotate_both(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);
void				rev_rotate(t_list **stack);
void				rra(t_list **stack_a, bool write);
void				rrb(t_list **stack_b, bool write);
void				rrr(t_list **stack_a, t_list **stack_b, bool write);
void				push(t_list **dest, t_list **src);
void				pa(t_list **stack_a, t_list **stack_b, bool write);
void				pb(t_list **stack_b, t_list **stack_a, bool write);
void				ft_error(t_list *stack_a, char **string);
void				free_stack(t_list **stack);
void				free_for_string(char **string);
#endif