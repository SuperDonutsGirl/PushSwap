/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:40:17 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 15:40:20 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	swap_a(t_stack *s)
{
	int	tmp;

	if (s->len_a != -1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
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
}
