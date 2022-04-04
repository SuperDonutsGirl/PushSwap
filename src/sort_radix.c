/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:02:18 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/09 13:02:31 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_tab(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s->len)
	{
		j = 0;
		s->num = s->a[i];
		while (s->sort[j] != s->num)
			j++;
		s->a[i] = j;
		i++;
	}
}

void	chunck_tab(t_stack *s)
{
	int	i;

	i = 0;
	while (i <= s->len_a)
	{
		s->chunck[i] = s->a[i] >> s->shift & 1;
		i++;
	}
}

void	radix_sort(t_stack *s, int last)
{
	int	i;

	i = 0;
	while (i <= last)
	{
		if ((s->a[0] >> s->shift & 1) == 1)
			rotate_a(s);
		else
			push_b(s);
		i++;
	}
	if (s->len_a > s->len - i)
	{
		while (i <= s->len)
		{
			rotate_a(s);
			i++;
		}
	}
	while (s->len_b != -1)
		push_a(s);
}

void	radix(t_stack *s)
{
	int	shift_max;
	int	last;

	quick_sort(s->sort, 0, s->len);
	index_tab(s);
	shift_max = 0;
	while ((s->len >> shift_max) != 0)
		shift_max++;
	s->shift = 0;
	while (s->shift < shift_max)
	{
		chunck_tab(s);
		last = found_last_zero(s);
		radix_sort(s, last);
		s->shift++;
	}
}
