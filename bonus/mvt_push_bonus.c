/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:38:53 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 15:38:54 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	push_a(t_stack *s)
{
	int	tmp;
	int	ia;
	int	ib;

	ib = -1;
	ia = s->len + 1;
	if (s->len_b != -1)
	{
		tmp = s->b[0];
		while (++ib < s->len_b)
			s->b[ib] = s->b[ib + 1];
		if (s->len_a != -1)
		{
			while (--ia > 0)
				s->a[ia] = s->a[ia - 1];
		}
		s->a[0] = tmp;
		s->b[s->len_b] = 0;
		s->len_b--;
		s->len_a++;
	}
}

void	push_b(t_stack *s)
{
	int	tmp;
	int	ia;
	int	ib;

	ia = -1;
	ib = s->len + 1;
	if (s->len_a != -1)
	{
		tmp = s->a[0];
		while (++ia < s->len_a)
			s->a[ia] = s->a[ia + 1];
		if (s->len_b != -1)
		{
			while (--ib > 0)
				s->b[ib] = s->b[ib - 1];
		}
		s->b[0] = tmp;
		s->a[s->len_a] = 0;
		s->len_a--;
		s->len_b++;
	}
}
