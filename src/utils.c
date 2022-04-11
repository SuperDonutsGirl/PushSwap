/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:07:36 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/05 03:07:45 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
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

int	output_error(t_stack *s, int error)
{
	if (s)
	{
		if (s->ac == 2)
			ft_free(s->av);
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		if (s->sort)
			free(s->sort);
		if (s->chunck)
			free(s->chunck);
		free(s);
	}
	if (error == 1)
		return (write(2, "Error\n", 6));
	else
		return (0);
}
