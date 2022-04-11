/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:44:31 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/22 15:44:33 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_split_argv(char **argv, t_stack *s)
{
	int		i;

	s->av = ft_split(argv[1], 32);
	if (!s->av)
		return (0);
	i = 0;
	while (s->av[i])
		i++;
	s->len_str = i;
	if (!check_is_valid(s->av))
		return (0);
	return (1);
}
