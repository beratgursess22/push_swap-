/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:54:23 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:54:24 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_numbers(int argc, char **argv, int *size)
{
	char	**full_argv;
	char	*combine_argv;
	char	*before_full_name;
	char	*temp;
	int		i;

	i = 1;
	before_full_name = ft_strdup("");
	while (i < argc)
	{
		combine_argv = ft_strjoin(argv[i], " ");
		temp = before_full_name;
		before_full_name = ft_strjoin(before_full_name, combine_argv);
		free(temp);
		free(combine_argv);
		i++;
	}
	full_argv = ft_split(before_full_name, ' ');
	i = 0;
	while (full_argv[i])
		i++;
	*size = i;
	free(before_full_name);
	return (full_argv);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new;

	len = ft_strlen(s1);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len + 1);
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_countwords(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		tab_index;
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tab_index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > k)
			tab[tab_index++] = ft_substr(s, k, i - k);
	}
	tab[tab_index] = NULL;
	return (tab);
}
