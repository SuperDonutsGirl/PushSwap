/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:19:57 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 15:19:59 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long		nb;
	int			neg;
	int			i;

	nb = 0;
	neg = 1;
	i = 0;
	if (str[0] == '-')
	{
		i = 1;
		neg = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
		if (neg == -1 && nb > 2147483648)
			return (0);
		if (neg == 1 && nb > 2147483647)
			return (-1);
	}
	return (nb * neg);
}

int	no_duplicate(t_stack *s, int nb, int i)
{
	while (i <= s->len)
	{
		if (nb == s->a[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}

int	output_error(t_stack *s, int error)
{
	if (s)
	{
		if (s->ac == 2)
			free_split(s->av);
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		free(s);
	}
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	else
		exit (EXIT_SUCCESS);

}
