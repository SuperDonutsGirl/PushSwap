/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:55:10 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:55:12 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	extraction_minus(t_stack *s)
{
	int	imin;

	imin = found_min(s->len_a, s->a);
		if (imin <= s->len_a / 2 + 1)
		{
			while (imin-- > 0)
				rotate_a(s);
		}
		else
		{
			while (imin++ <= s->len_a)
				reverse_a(s);
		}
}

void	extraction_sort(t_stack *s)
{
	while (s->len_a != 4)
	{
		extraction_minus(s);
		if (!is_sorted(s))
			push_b(s);
		else
			break ;
	}
	if (s->len_a == 4)
		sort_5(s);

	while (s->len_b >= 0)
		push_a(s);
}

