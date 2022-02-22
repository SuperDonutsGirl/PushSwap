/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_found.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:41:14 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:41:19 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_min(int len_s, int *stack)
{
	int x;
	int i;
	int min;

	i = len_s;
	min = stack[0];
	x = 0;
	while (i > 0)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			x = i;
		}
		i--;
	}
	return (x);
}

int	only_one(t_stack *s)
{
	int	i;

	i = 0;
	while (i <= s->len_a)
	{
		//printf("a la position %d, il y a %d\n", i, s->chunck[i]);
		if (s->chunck[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	only_zero(t_stack *s)
{
	int	i;

	i = 0;
	while (i <= s->len_a)
	{
		if (s->chunck[i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	found_last_zero(t_stack *s)
{
	int	i;
	int x;

	i = 0;
	x = s->len;
	while (i <= s->len_a)
	{
		if (s->chunck[i] == 0)
			x = i;
		i++;
	}

	return (x);
}

int	found_zero(t_stack *s)
{
	int	i;
	//int x;

	i = 0;
	//x = s->len;
	while (i <= s->len_a)
	{
		if (s->chunck[i] == 0)
			return(i);
		i++;
	}
	// return -1 si jamais il y a une 0 ?
	return (i);
}

