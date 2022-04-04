/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:09:57 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 15:09:58 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	check_is_valid(char **arg)
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
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	check_split_argv(char **argv, t_stack *s)
{
	int		i;

	s->av = ft_split(argv[1], 32);
	i = 0;
	while (s->av[i])
		i++;
	s->len_str = i;
	if (i <= 1)
		return (0);
	if (!check_is_valid(s->av))
		return (0);
	return (1);
}

int	check_params(int argc, char **argv, t_stack *s)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
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
