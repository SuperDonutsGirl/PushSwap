/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:35:31 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:35:34 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *s)
{
	if (!is_sorted(s))
		swap_a(s);
}

void	sort_3(t_stack *s)
{
	int	i;

	i = s->size_diff;
	if (s->a[i] > s->a[i + 1] && s->a[i + 1] < s->a[i + 2]
		&& s->a[i] < s->a[i + 2])
		swap_a(s);
	if (s->a[i] > s->a[i + 1] && s->a[i + 1] < s->a[i + 2]
		&& s->a[i] > s->a[i + 2])
		rotate_a(s);
	if (s->a[i] < s->a[i + 1] && s->a[i + 1] > s->a[i + 2]
		&& s->a[i] < s->a[i + 2])
	{
		reverse_a(s);
		swap_a(s);
	}
	if (s->a[i] < s->a[i + 1] && s->a[i + 1] > s->a[i + 2]
		&& s->a[i] > s->a[i + 2])
		reverse_a(s);
	if (s->a[i] > s->a[i + 1] && s->a[i + 1] > s->a[i + 2])
	{
		rotate_a(s);
		swap_a(s);
	}
}

void	sort_4(t_stack *s)
{
	int	min;

	min = found_min(s, s->len_a, s->a);
	if (min <= 2)
	{
		while (min-- > 0 + s->size_diff)
			rotate_a(s);
	}
	else
	{
		while (min++ <= s->len)
			reverse_a(s);	
	}
	push_b(s);
	sort_3(s);
	push_a(s);
}

void	sort_5(t_stack *s)
{
	int	min;
	if (is_sorted(s))
		return ;
	min = found_min(s, s->len_a, s->a);
	if (min <= 2)
	{
		while (min-- > 0 + s->size_diff)
			rotate_a(s);
	}
	else
	{
		while (min++ <= s->len)
			reverse_a(s);	
	}
	push_b(s);
	sort_4(s);
	push_a(s);
}
