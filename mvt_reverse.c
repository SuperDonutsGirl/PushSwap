/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:51:06 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:51:08 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_stack *s)
{
	int		tmp;
	size_t	i;

	i = s->len_a;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = tmp;
	write(1, "rra\n", 4);
}

void	reverse_b(t_stack *s)
{
	int		tmp;
	size_t	i;

	i = s->len_b;
	tmp = s->b[i];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = tmp;
	write(1, "rrb\n", 4);
}

void	reverse_ab(t_stack *s)
{
	int		tmp;
	size_t	i;

	i = s->len_a;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[i] = tmp;
	i = s->len_b;
	tmp = s->b[i];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[i] = tmp;
	write(1, "rrr\n", 4);
}
