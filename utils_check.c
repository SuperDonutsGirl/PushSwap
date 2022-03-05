/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:20:00 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/22 14:20:09 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_is_valid(char **arg)
{
	size_t	i;
	size_t	x;

	i = 1;
	while (arg[i])
	{
		if (ft_strlen(arg[i]) >= 10 && (ft_atoi(arg[i]) == 0
				|| ft_atoi(arg[i]) == -1))
			return (0);
		if (arg[i][0] == 45)
			x = 1;
		else
			x = 0;
		while (arg[i][x])
		{
			if (!ft_isdigit(arg[i][x]))
			{
				printf("ici\n");
				return (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}
int	check_params(int argc, char **argv, t_stack *s)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && !check_split_argv(argv, s))
		return (0);
	else if (argc > 2)
	{
		if (!check_is_valid(argv))
			return (0);
	}
	return (1);
}

int	check_duplicate(t_stack *s)
{
	int	i;
	int	nb;

	i = 0;
	while (i <= s->len)
	{
		nb = s->a[i];
		if (!no_duplicate(s, nb, i + 1))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->len_a)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
