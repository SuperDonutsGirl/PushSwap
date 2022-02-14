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

int	found_max(t_stack *s, int len_s, int *stack)
{
	int x;
	int i;
	int max;
	int top;

	i = s->len;
	top = i - len_s;
	max = stack[top];
	x = top;
	while (i > top)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			x = i;
		}
		i--;
	}
	return (x);
}

int	found_min(t_stack *s, int len_s, int *stack)
{
	int x;
	int i;
	int min;
	int top;

	i = s->len;
	top = i - len_s;
	min = stack[top];
	x = top;
	while (i > top)
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


