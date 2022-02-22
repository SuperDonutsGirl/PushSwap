/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:49:47 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:49:56 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *s)
{
	int	tmp;

	if (s->len_a != -1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *s)
{
	int	tmp;

	if (s->len_b != -1)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack *s)
{
	int	tmp;

	if (s->len_a != -1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
	if (s->len_b != -1)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
	write(1, "ss\n", 3);
}
