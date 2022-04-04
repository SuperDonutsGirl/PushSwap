/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_reverse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:39:07 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 15:39:08 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
}
