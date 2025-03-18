/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:54:28 by igurses           #+#    #+#             */
/*   Updated: 2025/03/15 13:54:29 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	buf = (char *)malloc((len + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

static void	max_check(long res, int sing, char **string, t_list **stack)
{
	if (sing == -1)
	{
		res *= sing;
	}
	if (res > INT_MAX || res < INT_MIN)
		ft_error(*stack, string);
}

int	ft_atoi(const char *str, char **string, t_list **stack)
{
	int		i;
	int		sing;
	long	res;

	res = 0;
	sing = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = sing * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - '0'));
		max_check(res, sing, string, stack);
		i++;
	}
	return (res * sing);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
